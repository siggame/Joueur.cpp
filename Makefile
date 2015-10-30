# Set this to the location of your Boost libraries
BOOST_ROOT= 
# Set this to TRUE to use static Boost libraries
Boost_USE_STATIC_LIBS= FALSE
# Set this to any extra options you want to pass to cmake (Advanced)
CMAKE_EXTRAS= 

# Ignore stuff past here, don't edit it

all: dependencies core

dependencies:
ifeq (,$(wildcard ./build/CMakeCache.txt))
	@mkdir build || true
ifeq ("$(BOOST_ROOT)","")
	  @cd build && cmake .. -DCMAKE_BUILD_TYPE:STRING=RelWithDebInfo -DBoost_USE_STATIC_LIBS=$(USE_STATIC_LIBS) $(CMAKE_EXTRAS)
else
	  @cd build && cmake .. -DCMAKE_BUILD_TYPE:STRING=RelWithDebInfo -DBoost_USE_STATIC_LIBS=$(USE_STATIC_LIBS) -DBOOST_ROOT:PATH=$(BOOST_ROOT) $(CMAKE_EXTRAS)
endif
endif

core:
	@cd build && $(MAKE)

clean:
	@rm -rf build
