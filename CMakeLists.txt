if(CMAKE_MAJOR_VERSION LESS 3)
   cmake_minimum_required(VERSION 2.6.0 FATAL_ERROR)
   setEXPLICIT_VERSION FALSE)
elseif()
   cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
   set(EXPLICIT_VERSION TRUE)
endif()

#remove a warning on Windows
if(COMMAND cmake_policy)
   cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

get_filename_component(srcdir "${CMAKE_SOURCE_DIR}" REALPATH)
get_filename_component(bindir "${CMAKE_BINARY_DIR}" REALPATH)

#prevent in-source build
if("${srcdir}" STREQUAL "${bindir}")
   message(FATAL_ERROR "In-source builds are not allowed.")
endif()

set(PROG_NAME "cpp-client")

project(${PROG_NAME})

#build the libraries as well
add_subdirectory(joueur/libraries)

set(BOOST_INCLUDEDIR /usr/include)
find_package(Boost COMPONENTS regex date_time system coroutine thread context REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost was not found!")
endif(NOT Boost_FOUND)

#find generated files
file(GLOB FILES RELATIVE
     "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/games/*/*")

#add source files
add_executable(${PROG_NAME} ${FILES}
                            joueur/src/any.hpp
                            joueur/src/attr_wrapper.hpp
                            joueur/src/base_ai.cpp
                            joueur/src/base_ai.hpp
                            joueur/src/base_game.hpp
                            joueur/src/base_game.cpp
                            joueur/src/base_object.hpp
                            joueur/src/connection.cpp
                            joueur/src/connection.hpp
                            joueur/src/delta.cpp
                            joueur/src/delta.hpp
                            joueur/src/exceptions.hpp
                            joueur/src/main.cpp
                            joueur/src/register.cpp
                            joueur/src/register.hpp
                            joueur/src/sgr.hpp)

#link to netlink (static)
target_link_libraries(${PROG_NAME} static)

#include library files
include_directories(${PROG_NAME} "joueur/libraries/netLink/include/"
                                 "joueur/libraries/tclap/include/"
                                 "joueur/libraries/rapidjson/include/"
                                 "coroutine/include")

#stole this from netlink
if(WIN32)
   target_link_libraries(${PROG_NAME} ws2_32)
   set(ver ${CMAKE_SYSTEM_VERSION})
   string(REPLACE "." "" ver ${ver})
   string(REGEX REPLACE "([0-9])" "0\\1" ver ${ver})
   add_definitions(-D_WIN32_WINNT=0x${ver})
   add_definitions(-DWIN32)
elseif(UNIX OR MINGW)
   find_package(Threads)
   set(LINK_LIBS ${CMAKE_THREAD_LIBS_INIT})
endif()

target_link_libraries(${PROG_NAME} ${Boost_LIBRARIES} ${LINK_LIBS})

#set C++11
if(EXPLICIT_VERSION)
   set_property(TARGET ${PROG_NAME} PROPERTY CXX_STANDARD 11)
   set_property(TARGET ${PROG_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
else()
   if(UNIX OR MINGW)
      set_target_properties(${PROG_NAME} PROPERTIES COMPILE_OPTIONS "-std=c++11")
   endif()
endif()

#bloop
add_definitions(-DCHESSER_NO_14)