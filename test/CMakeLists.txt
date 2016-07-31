project( bf-log-test )

cmake_minimum_required(VERSION 2.8)

set( CMAKE_CXX_FLAGS "-std=c++1y -Wall -Wextra" )

# Test writing to stdout
file(GLOB PKG_SOURCE test-stdout.cpp )
add_executable( test-stdout.out ${PKG_SOURCE} )
target_link_libraries( test-stdout.out bf-log )

# test writing to stderr
file( GLOB PKG_SOURCE test-stderr.cpp )
add_executable( test-stderr.out ${PKG_SOURCE} )
target_link_libraries( test-stderr.out bf-log )

# Test writing to a file
file( GLOB PKG_SOURCE test-file.cpp )
add_executable( test-file.out ${PKG_SOURCE} )
target_link_libraries( test-file.out bf-log )

# Test writing to a file and stdout
file( GLOB PKG_SOURCE test-file+stdout.cpp )
add_executable( test-file+stdout.out ${PKG_SOURCE} )
target_link_libraries( test-file+stdout.out bf-log )

# Test writing to stdout with multithreading
file( GLOB PKG_SOURCE test-threading.cpp )
add_executable( test-threading.out ${PKG_SOURCE} )
target_link_libraries( test-threading.out bf-log )
