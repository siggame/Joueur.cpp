if(CMAKE_MAJOR_VERSION LESS 3)
   cmake_minimum_required(VERSION 2.6.0 FATAL_ERROR)
   set(EXPLICIT_VERSION FALSE)
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
add_subdirectory(libraries)

#find generated files
file(GLOB FILES RELATIVE
     "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/games/*/*")

#add source files
add_executable(${PROG_NAME} ${FILES}
                            src/attr_wrapper.hpp
                            src/base_ai.cpp
                            src/base_ai.hpp
                            src/base_game.hpp
                            src/connection.cpp
                            src/connection.hpp
                            src/exceptions.hpp
                            src/main.cpp
                            src/register.cpp
                            src/register.hpp
                            src/sgr.hpp)

#link to netlink (static)
target_link_libraries(${PROG_NAME} static)

#include library files
include_directories(${PROG_NAME} "libraries/netLink/include/"
                                 "libraries/tclap/include/"
                                 "libraries/rapidjson/include/")

#stole this from netlink
if(WIN32)
   target_link_libraries(${PROG_NAME} ws2_32)
   set(ver ${CMAKE_SYSTEM_VERSION})
   string(REPLACE "." "" ver ${ver})
   string(REGEX REPLACE "([0-9])" "0\\1" ver ${ver})
   add_definitions(-D_WIN32_WINNT=0x${ver})
   add_definitions(-DWIN32)
endif(WIN32)

#set C++11
if(EXPLICIT_VERSION)
   set_property(TARGET ${PROG_NAME} PROPERTY CXX_STANDARD 11)
   set_property(TARGET ${PROG_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
else()
   if(UNIX OR MINGW)
      set_target_properties(${PROG_NAME} PROPERTIES COMPILE_FLAGS "-std=c++11")
   endif()
endif()
