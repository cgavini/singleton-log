#include <mutex>
#include "Log.hpp"

// We have to define the static instance here so that member functions can use it.
shared_ptr<bf::Log> bf::Log::log;
std::mutex mtx;

shared_ptr<bf::Log> bf::Log::getInstance() {
	if( !log ) {
		log = shared_ptr<bf::Log>( new bf::Log() );
	}
	return log;
}

void bf::Log::setTarget( bf::Log::Target target ) {
	this->logTarget = target;
}

void bf::Log::setLevel( bf::Log::Level level ) {
	this->logLevel = level;
}

int bf::Log::setFile( string fileName ) {
	// Make sure we can open the file for writing
	ofstream logFile( fileName, ofstream::app );
	if( !logFile.is_open() ){
		// bf::Log the failure and return an error code
		this->log->write( bf::Log::Level::ERR, "Failed to open log file '" + this->logFile + "'" );
		return 1;
	}

	this->logFile = fileName;
	return 0;
}

bf::Log::Level bf::Log::getLevel() {
	return this->logLevel;
}

string bf::Log::levelToString( bf::Log::Level level ) {
	return this->levelMap[ level ];
}

void bf::Log::write( bf::Log::Level level, string message ) {
	string toLog;

	// Only log if we're at or above the pre-defined severity
	if( level < this->logLevel ) {
		return;
	}

	// bf::Log::Target::DISABLED takes precedence over other targets
	if( ( this->logTarget & bf::Log::Target::DISABLED ) == bf::Log::Target::DISABLED ) {
		return;
	}

	// Append the log level if enabled
	if( this->levelEnabled ){
		toLog += this->levelToString( level );
	}

	// Append the current date and time if enabled
	if( this->timestampEnabled ){
		std::time_t time = system_clock::to_time_t( system_clock::now() );
		struct tm timeinfo;
		localtime_s(&timeinfo, &time );
		struct tm* timeStruct = &timeinfo;

		char timeStr[ 80 ];
		strftime( timeStr, 80, "%d/%b/%Y:%H:%M:%S %z", timeStruct );
		toLog += " [" + string( timeStr ) + "]";
	}

	// Append the message to our log statement
	toLog += " " + message;

	// bf::Log to stdout if it's one of our targets
	if( ( this->logTarget & bf::Log::Target::STDOUT ) == bf::Log::Target::STDOUT ) {
		mtx.lock();
		std::cout << toLog << std::endl;
		mtx.unlock();
	}
	
	// bf::Log to stderr if it's one of our targets
	if( ( this->logTarget & bf::Log::Target::STDERR ) == bf::Log::Target::STDERR ) {
		mtx.lock();
		std::cerr << toLog << std::endl;
		mtx.unlock();
	}

	// bf::Log to a file if it's one of our targets and we've set a logFile
	if( ( this->logTarget & bf::Log::Target::LOG_FILE ) == bf::Log::Target::LOG_FILE && this->logFile != "" ) {
		mtx.lock();
		ofstream logFile( this->logFile, ofstream::app );
		logFile << toLog << "\n";
		logFile.close();
		mtx.unlock();
	}
}
