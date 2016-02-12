#include "Log.hpp"

// We have to define the static instance here so that member functions can use it.
shared_ptr<Log> Log::log;

shared_ptr<Log> Log::getInstance() {
	if( !log ) {
		log = shared_ptr<Log>( new Log() );
	}
	return log;
}

void Log::setTarget( Log::Target target ) {
	this->logTarget = target;
}

void Log::setLevel( Log::Level level ) {
	this->logLevel = level;
}

int Log::setFile( string fileName ) {
	// Make sure we can open the file for writing
	ofstream logFile( fileName, ofstream::app );
	if( !logFile.is_open() ){
		// Log the failure and return an error code
		this->log->write( Log::Level::ERR, "Failed to open log file '" + this->logFile + "'" );
		return 1;
	}

	this->logFile = fileName;
	return 0;
}

Log::Level Log::getLevel() {
	return this->logLevel;
}

string Log::levelToString( Log::Level level ) {
	return this->levelMap[ level ];
}

void Log::write( Log::Level level, string message ) {
	// Only log if we're at or above the pre-defined severity
	if( level < this->logLevel ) {
		return;
	}

	// Log::Target::DISABLED takes precedence over other targets
	if( ( this->logTarget & Log::Target::DISABLED ) == Log::Target::DISABLED ) {
		return;
	}

	// Prepend the log level if enabled
	if( this->levelEnabled ){
		message = this->levelToString( level ) + static_cast<string>( "\t" ) + message;
	}

	// Prepend the current date and time if enabled
	if( this->timestampEnabled ){
		time_t rawtime;
		time( &rawtime );
		string timeStr( ctime( &rawtime ) );
		message = timeStr.substr( 0, timeStr.length()-1 ) + static_cast<string>( "\t" ) + message;
	}

	// Log to stdout if it's one of our targets
	if( ( this->logTarget & Log::Target::STDOUT ) == Log::Target::STDOUT ) {
		std::cout << message << std::endl;
	}
	
	// Log to stderr if it's one of our targets
	if( ( this->logTarget & Log::Target::STDERR ) == Log::Target::STDERR ) {
		std::cerr << message << std::endl;
	}

	// Log to a file if it's one of our targets and we've set a logFile
	if( ( this->logTarget & Log::Target::LOG_FILE ) == Log::Target::LOG_FILE && this->logFile != "" ) {
		ofstream logFile( this->logFile, ofstream::app );
		logFile << message << "\n";
		logFile.close();
	}
}
