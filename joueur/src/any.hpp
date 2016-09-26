#ifndef ANY_HPP
#define ANY_HPP

//this is clunky, but it kinda works
#include "base_object.hpp"

#include <typeinfo>
#include <memory>
#include <type_traits>

namespace cpp_client
{

//Holder of any types
class Any
{
public:
   Any() noexcept :
      data_{nullptr}
   {
      ;
   }

   template<typename T>
   Any(T&& other) noexcept :
      data_(new holder2<T>(std::forward<T>(other)))
   {
      ;
   }

   explicit operator bool() const noexcept
   {
      return data_ != nullptr;
   }

   //enable moving and disable copying
   Any(Any&& rhs) = default;
   Any& operator=(Any&& rhs) = default;
   Any(const Any&) = delete;
   Any& operator=(const Any&) = delete;

   const std::type_info& type() const noexcept
   {
      if(data_)
      {
         return data_->type();
      }
      return typeid(void);
   }

   //base types
   template<typename T>
   typename std::enable_if<std::is_fundamental<T>::value || std::is_pointer<T>::value, T&>::type as()
   {
      if(typeid(T) != data_->type())
      {
         throw std::bad_cast{};
      }
      return *static_cast<T*>(data_->get());
   }

   template<typename T>
   typename std::enable_if<std::is_fundamental<T>::value || std::is_pointer<T>::value, const T&>::type as() const
   {
      if(typeid(T) != data_->type())
      {
         throw std::bad_cast{};
      }
      return *static_cast<T*>(data_->get());
   }

   //classes
   template<typename T>
   typename std::enable_if<std::is_compound<T>::value && !std::is_pointer<T>::value, T&>::type as()
   {
      return dynamic_cast<T&>(*static_cast<T*>(data_->get()));
   }

   template<typename T>
   typename std::enable_if<std::is_compound<T>::value && !std::is_pointer<T>::value, const T&>::type as() const
   {
      return dynamic_cast<T&>(*static_cast<T*>(data_->get()));
   }

   void reset(std::shared_ptr<Base_object>&& obj = nullptr)
   {
      if(data_)
      {
         data_->reset(std::move(obj));
      }
   }

   std::shared_ptr<Base_object> get()
   {
      if(data_)
      {
         return data_->get_ptr();
      }
      return nullptr;
   }

private:
   struct holder
   {
      holder(const holder& other) = default;
      holder(holder&& other) = default;
      holder() = default;
      virtual ~holder() noexcept = default;
      virtual const std::type_info& type() const noexcept = 0;
      virtual void* get() noexcept = 0;
      virtual const void* get() const noexcept = 0;
      virtual void reset(std::shared_ptr<Base_object>&& obj){}
      virtual std::shared_ptr<Base_object> get_ptr(){ return nullptr; }
   };

   //non-smart pointer version
   template<typename T, typename = void>
   struct overload_things
   {
      void reset(T& obj_, std::shared_ptr<Base_object>&& obj) const
      {
         ;
      }

      std::shared_ptr<Base_object> get_ptr(T& obj_) const
      {
         return nullptr;
      }
   };

   //smart pointer version
   template<typename T>
   struct overload_things<
      T,
      typename std::enable_if<std::is_same<decltype(std::declval<T>().unique()),
                                           decltype(std::declval<T>().unique())>::value>::type>
   {
      void reset(T& obj_, std::shared_ptr<Base_object>&& obj) const
      {
         obj_ = std::dynamic_pointer_cast<typename std::decay<T>::type::element_type>(obj);
      }

      std::shared_ptr<Base_object> get_ptr(T& obj_) const
      {
         return std::dynamic_pointer_cast<Base_object>(obj_);
      }
   };

   template<typename T>
   struct holder2 : public holder
   {
      virtual void reset(std::shared_ptr<Base_object>&& obj) override
      {
         overload_things<T>{}.reset(obj_, std::move(obj));
      }

      virtual std::shared_ptr<Base_object> get_ptr() override
      {
         return overload_things<T>{}.get_ptr(obj_);
      }

      virtual ~holder2() noexcept override = default;
      virtual const std::type_info& type() const noexcept override { return typeid(T); }
      virtual void* get() noexcept override { return static_cast<void*>(&obj_); }
      virtual const void* get() const noexcept override { return static_cast<const void*>(&obj_); }

      template<typename U>
      holder2(U&& obj) : obj_(std::forward<U>(obj)) {}

      template<typename U>
      holder2(holder2<U>&& other) : obj_(std::forward<U>(other.obj_)) {}

      T obj_;
   };

   std::unique_ptr<holder> data_;
};

}

#endif // ANY_HPP
