#include <string>
#include "Log.cpp"
#include <iostream>

int main(){
	Log* log = Log::getInstance();
	log->setLevel( Log::Level::WARNING );
	log->setTarget( Log::Target::LOG_FILE | Log::Target::STDOUT );
	log->setFile( "./logs/test.log" );

	unsigned int i = 0;
	string s = "Hello, world";
	while( i < s.length() ) {
		log->write( Log::Level::WARNING, "Hello, world" + i++ );
	}
}
