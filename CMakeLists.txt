project( log )

cmake_minimum_required(VERSION 2.8)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set( CMAKE_CXX_FLAGS "-std=c++1y -Wall -Wextra -Werror" )

file(GLOB PKG_SOURCE *.cpp)

add_library( log SHARED ${PKG_SOURCE} )

add_subdirectory( test )
