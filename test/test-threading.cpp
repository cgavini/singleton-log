#include <string>
#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <chrono>
#include <exception>
#include "../Log.hpp"

void aThreadFunction( std::string threadName, int n, std::promise<int> p ) {
	shared_ptr<bf::Log> log = bf::Log::getInstance();
	if( n <= 0 ) {
		log->write( bf::Log::Level::ERR, threadName + " exiting...n must be a positive integer." );
		p.set_value( 1 );
		return;
	}

	for( int i = 1; i <= n; i++ ) {
		log->write( bf::Log::Level::INFO, "Looping through aThreadFunction in " + threadName + "...on iteration " + std::to_string( i ) + "." );
		std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
	}
	p.set_value( 0 );
}

int main(){
	shared_ptr<bf::Log> log = bf::Log::getInstance();
	log->setLevel( bf::Log::Level::DEBUG );

	unsigned numThreads = std::thread::hardware_concurrency();
	log->write( bf::Log::Level::DEBUG, "Number of threads available: " + std::to_string( numThreads ) );

	std::promise<int> p1;
	std::future<int> f1 = p1.get_future();

	std::promise<int> p2;
	std::future<int> f2 = p2.get_future();

	log->write( bf::Log::Level::DEBUG, "Starting myThread1." );
	std::thread myThread1( aThreadFunction, "myThread1", 5, std::move( p1 ) );

	log->write( bf::Log::Level::DEBUG, "Starting myThread2." );
	std::thread myThread2( aThreadFunction, "myThread2", -10, std::move( p2 ) );

	int t1Errno = f1.get();
	int t2Errno = f2.get();
	log->write( t1Errno > 0 ? bf::Log::Level::ERR : bf::Log::Level::INFO, "Received a return code for thread 1: " + std::to_string( t1Errno ) + "." );
	log->write( t2Errno > 0 ? bf::Log::Level::ERR : bf::Log::Level::INFO, "Received a return code for thread 2: " + std::to_string( t2Errno ) + "." );

	log->write( bf::Log::Level::DEBUG, "Joining myThread1." );
	myThread1.join();

	log->write( bf::Log::Level::DEBUG, "Joining myThread2." );
	myThread2.join();
}
