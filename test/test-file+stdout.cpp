#include <string>
#include "Log.cpp"
#include <iostream>

int main(){
	Log* log = Log::getLog();
	log->setTarget( Log::Target::LOG_FILE | Log::Target::STDOUT );
	log->setLogFile( "./logs/test.log" );

	int i = 0;
	string s = "Hello, world";
	while( i < s.length() ) {
		log->write( Log::Level::DEBUG, "Hello, world" + i++ );
	}
}
