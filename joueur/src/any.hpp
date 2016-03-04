#ifndef ANY_HPP
#define ANY_HPP

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
   Any(const T& other) noexcept :
      data_(new holder2<T>(other))
   {
      ;
   }

   template<typename T>
   Any(T&& other) noexcept :
      data_(new holder2<T>(std::move(other)))
   {
      ;
   }

   //enable moving - diable copying
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
   typename std::enable_if<std::is_fundamental<T>::value, T&>::type as()
   {
      if(typeid(T) != data_->type())
      {
         throw std::bad_cast{};
      }
      return *static_cast<T*>(data_->get());
   }

   //classes
   template<typename T>
   typename std::enable_if<std::is_compound<T>::value, T&>::type as()
   {
      return dynamic_cast<T&>(*static_cast<T*>(data_->get()));
   }

private:
   struct holder
   {
      virtual ~holder() noexcept = default;
      virtual const std::type_info& type() const noexcept = 0;
      virtual void* get() noexcept = 0;
   };

   template<typename T>
   struct holder2 : public holder
   {
      virtual ~holder2() noexcept override = default;
      virtual const std::type_info& type() const noexcept override { return typeid(T); }
      virtual void* get() noexcept override { return static_cast<void*>(&obj_); }
      holder2(const T& obj) : obj_(obj){}
      T obj_;
   };

   std::unique_ptr<holder> data_;
};

}

#endif // ANY_HPP
