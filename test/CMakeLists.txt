project( singleton-log-test )

cmake_minimum_required(VERSION 2.8)

set( CMAKE_CXX_FLAGS "-std=c++1y -Wall -Wextra -Werror -pthread" )

# Test writing to stdout
file(GLOB PKG_SOURCE test-stdout.cpp )
add_executable( test-stdout ${PKG_SOURCE} )
target_link_libraries( test-stdout singleton-log )

# test writing to stderr
file(GLOB PKG_SOURCE test-stderr.cpp )
add_executable( test-stderr ${PKG_SOURCE} )
target_link_libraries( test-stderr singleton-log )

# Test writing to a file
file(GLOB PKG_SOURCE test-file.cpp )
add_executable( test-file ${PKG_SOURCE} )
target_link_libraries( test-file singleton-log )

# Test writing to a file and stdout
file(GLOB PKG_SOURCE test-file+stdout.cpp )
add_executable( test-file+stdout ${PKG_SOURCE} )
target_link_libraries( test-file+stdout singleton-log )

# Test writing to stdout with multithreading
file(GLOB PKG_SOURCE test-threading.cpp )
add_executable( test-threading ${PKG_SOURCE} )
target_link_libraries( test-threading singleton-log )
