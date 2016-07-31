project( singleton-log )

cmake_minimum_required( VERSION 2.8 )

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

set( CMAKE_CXX_FLAGS "-std=c++1y -Wall -Wextra" )

file( GLOB PKG_SOURCE *.cpp )

add_library( bf-log SHARED ${PKG_SOURCE} )
install( TARGETS bf-log
	LIBRARY DESTINATION lib
	#INCLUDES DESTINATION include/bf-log
		)
install( FILES Log.hpp
	DESTINATION include/bf-log
	)

# Uncomment to build tests
add_subdirectory( test )
