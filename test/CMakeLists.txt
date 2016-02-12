project( singleton-log-test )

cmake_minimum_required(VERSION 2.8)

set( CMAKE_CXX_FLAGS "-std=c++1y -Wall -Wextra -Werror -pthread" )

# Test writing to stdout
file(GLOB PKG_SOURCE test-stdout.cpp )
add_executable( test-stdout.out ${PKG_SOURCE} )
target_link_libraries( test-stdout.out singleton-log )

# test writing to stderr
file( GLOB PKG_SOURCE test-stderr.cpp )
add_executable( test-stderr.out ${PKG_SOURCE} )
target_link_libraries( test-stderr.out singleton-log )

# Test writing to a file
file( GLOB PKG_SOURCE test-file.cpp )
add_executable( test-file.out ${PKG_SOURCE} )
target_link_libraries( test-file.out singleton-log )

# Test writing to a file and stdout
file( GLOB PKG_SOURCE test-file+stdout.cpp )
add_executable( test-file+stdout.out ${PKG_SOURCE} )
target_link_libraries( test-file+stdout.out singleton-log )

# Test writing to stdout with multithreading
file( GLOB PKG_SOURCE test-threading.cpp )
add_executable( test-threading.out ${PKG_SOURCE} )
target_link_libraries( test-threading.out singleton-log )
