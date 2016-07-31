#include <string>
#include "../Log.hpp"
#include <iostream>
#include <thread>
#include <chrono>

void sleep( int seconds ) {
	std::this_thread::sleep_for( std::chrono::seconds( seconds ) );
}

int main(){
	shared_ptr<bf::Log> log = bf::Log::getInstance();
	log->setLevel( bf::Log::Level::DEBUG );

	log->write( bf::Log::Level::DEBUG, "x = 10" );
	sleep( 2 );
	log->write( bf::Log::Level::ERR, "Oh no! We've encountered an error!");
	sleep( 2 );
	log->write( bf::Log::Level::WARNING, "Just so you know, you're using this wrong" );
	sleep( 2 );
	log->write( bf::Log::Level::DEBUG, "x is now 15" );

}
