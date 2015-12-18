project( log-test )

cmake_minimum_required(VERSION 2.8)

set( CMAKE_CXX_FLAGS "-std=c++1y" )

file(GLOB PKG_SOURCE test-stdout.cpp )
add_executable( test-stdout ${PKG_SOURCE})
target_link_libraries( test-stdout log )

file(GLOB PKG_SOURCE test-file.cpp )
add_executable( test-file ${PKG_SOURCE})
target_link_libraries( test-file log )

file(GLOB PKG_SOURCE test-file+stdout.cpp )
add_executable( test-file+stdout ${PKG_SOURCE})
target_link_libraries( test-file+stdout log )
