#include <string>
#include "Log.hpp"
#include <iostream>

int main(){
	Log* log = Log::getInstance();
	log->setLevel( Log::Level::INFO );
	log->setTarget( Log::Target::LOG_FILE );
	log->setFile( "test.log" );

	unsigned int i = 0;
	string s = "Hello, world";
	while( i < s.length() ) {
		log->write( Log::Level::INFO, "Hello, world" + i++ );
	}
}
