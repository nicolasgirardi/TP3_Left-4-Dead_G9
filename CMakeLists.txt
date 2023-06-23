cmake_minimum_required(VERSION 3.10.2)
project(left4dead)

set (CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -Werror -pedantic")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -DDEBUG -fno-inline ")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

file(GLOB_RECURSE COMMON_SRCS ./common_libs/src/*.cpp)
file(GLOB_RECURSE CLIENT_SRCS ./client/src/*.cpp)
file(GLOB_RECURSE SERVER_SRCS ./server/src/*.cpp)
list(FILTER CLIENT_SRCS EXCLUDE REGEX "main.cpp")
list(FILTER SERVER_SRCS EXCLUDE REGEX "main.cpp")

add_library(libcommon STATIC ${COMMON_SRCS})
add_library(libserver STATIC ${SERVER_SRCS})
add_library(libclient STATIC ${CLIENT_SRCS})
TARGET_LINK_LIBRARIES(libserver libcommon)
target_link_libraries(libclient libcommon)

add_executable(left4dead-client "client/src/main.cpp")
TARGET_LINK_LIBRARIES(left4dead-client libclient)

add_executable(left4dead-server "server/src/main.cpp")
TARGET_LINK_LIBRARIES(left4dead-server libserver)

install(TARGETS left4dead-server left4dead-client libclient libserver libcommon
        ARCHIVE DESTINATION "lib"
        RUNTIME DESTINATION "bin"
        INCLUDES DESTINATION "include")
