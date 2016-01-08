#include <string>
#include "../Log.hpp"
#include <iostream>


int main(){
	shared_ptr<Log> log = Log::getInstance();
	log->setLevel( Log::Level::DEBUG );
	log->setTarget( Log::Target::STDERR );

	unsigned int i = 0;
	string s = "Hello, world";
	while( i < s.length() ) {
		log->write( Log::Level::DEBUG, "Hello, world" + i++ );
	}
}
