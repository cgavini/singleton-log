#include "Log.hpp"

// Initialize our instance to NULL, so that we can test if we already have one
Log* Log::log = NULL;

// Allow targets to be combined
inline Log::Target operator&( Log::Target a, Log::Target b ){
	return static_cast<Log::Target>( static_cast<short>( a ) & static_cast<short>( b ) );
}
inline Log::Target operator|( Log::Target a, Log::Target b ){
	return static_cast<Log::Target>( static_cast<short>( a ) | static_cast<short>( b ) );
}

Log* Log::getLog() {
	if( log == NULL ) {
		log = new Log();
	}
	return log;
}

void Log::setTarget( Log::Target target ) {
	this->logTarget = target;
}

int Log::setLogFile( string fileName ) {
	ofstream logFile( fileName, ofstream::app );
	if( !logFile.is_open() ){
		this->log->write( Log::Level::ERR, "Failed to open log file '" + this->logFile + "'" );
		return 1;
	}

	this->logFile = fileName;
	return 0;
}

Log::Level Log::getLogLevel() {
	return this->logLevel;
}

string Log::logLevelToString( Log::Level level ) {
	return this->levelMap[ level ];
}

void Log::write( Log::Level level, string message ) {
	// Only log if we're at or above the pre-defined severity
	if( level < this->logLevel ) {
		return;
	}

	// Prepend the log level if enabled
	if( this->levelEnabled ){
		message = this->logLevelToString( this->logLevel ) + static_cast<string>( "\t" ) + message;
	}

	// Prepend the current date and time if enabled
	if( this->timestampEnabled ){
		time_t rawtime;
		time( &rawtime );
		string timeStr( ctime( &rawtime ) );
		message = timeStr.substr( 0, timeStr.length()-1 ) + static_cast<string>( "\t" ) + message;
	}

	// Log to stdout if it's our target
	if( ( this->logTarget & Log::Target::STDOUT ) == Log::Target::STDOUT ) {
		std::cout << message << std::endl;
	}

	// Log to a file if it's one of our targets and we've set a logFile
	if( ( this->logTarget & Log::Target::LOG_FILE ) == Log::Target::LOG_FILE && this->logFile != "" ) {
		ofstream logFile( this->logFile, ofstream::app );
		logFile << message << "\n";
		logFile.close();
	}
}
