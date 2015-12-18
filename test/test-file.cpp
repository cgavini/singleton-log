#include <string>
#include "Log.hpp"
#include <iostream>

int main(){
	Log* log = Log::getLog();
	log->setTarget( Log::Target::LOG_FILE );
	log->setLogFile( "test.log" );

	int i = 0;
	string s = "Hello, world";
	while( i < s.length() ) {
		log->write( Log::Level::DEBUG, "Hello, world" + i++ );
	}
}
