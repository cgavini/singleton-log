#include <string>
#include "../Log.hpp"
#include <iostream>


int main(){
	shared_ptr<bf::Log> log = bf::Log::getInstance();
	log->setLevel( bf::Log::Level::DEBUG );
	log->setTarget( bf::Log::Target::STDERR );

	unsigned int i = 0;
	string s = "Hello, world";
	while( i < s.length() ) {
		log->write( bf::Log::Level::DEBUG, "Hello, world" + i++ );
	}
}
