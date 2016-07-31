#include <string>
#include "../Log.hpp"
#include <iostream>

int main(){
	shared_ptr<bf::Log> log = bf::Log::getInstance();
	log->setLevel( bf::Log::Level::INFO );
	log->setTarget( bf::Log::Target::LOG_FILE );
	log->setFile( "test.log" );

	unsigned int i = 0;
	string s = "Hello, world";
	while( i < s.length() ) {
		log->write( bf::Log::Level::INFO, "Hello, world" + i++ );
	}
}
