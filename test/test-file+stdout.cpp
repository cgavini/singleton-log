#include <string>
#include "../Log.cpp"
#include <iostream>

int main(){
	std::shared_ptr<bf::Log> log = bf::Log::getInstance();
	log->setLevel( bf::Log::Level::WARNING );
	log->setTarget( bf::Log::Target::LOG_FILE | bf::Log::Target::STDOUT );
	log->setFile( "./logs/test.log" );

	unsigned int i = 0;
	string s = "Hello, world";
	while( i < s.length() ) {
		log->write( bf::Log::Level::WARNING, "Hello, world" + i++ );
	}
}
