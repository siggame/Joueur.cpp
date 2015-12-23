if(CMAKE_MAJOR_VERSION LESS 3)
    cmake_minimum_required(VERSION 2.6.0 FATAL_ERROR)
    set(CPP11_OKAY FALSE)
elseif()
    cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
    set(CPP11_OKAY TRUE)
endif()

# Get rid of a warning
if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

project(client)

# Find Boost
find_package(Boost COMPONENTS regex date_time system program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost was not found!")
endif(NOT Boost_FOUND)

# Find source files
file(GLOB FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/games/*/*" "${CMAKE_CURRENT_SOURCE_DIR}/joueur/*")

set(FILES ${FILES}
          gamesRegistry.h
          main.cpp)

# Find PThreads if needed
if(UNIX OR MINGW)
    find_package(Threads)
    set(LINK_LIBS ${CMAKE_THREAD_LIBS_INIT})
endif(UNIX OR MINGW)
          
# Add source files
add_executable(client ${FILES})

# Require C++11
if(CPP11_OKAY)
    set_property(TARGET client PROPERTY CXX_STANDARD 11)
    set_property(TARGET client PROPERTY CXX_STANDARD_REQUIRED ON)
else()
    if(UNIX OR MINGW)
        set_target_properties(client PROPERTIES COMPILE_FLAGS "-std=c++11")
    endif(UNIX OR MINGW)
endif()

# Link libraries
target_link_libraries(client ${LINK_LIBS} ${Boost_LIBRARIES})

# Need to link WinSockets and such on windows
if(WIN32)
    target_link_libraries(client wsock32 ws2_32)
endif(WIN32)
