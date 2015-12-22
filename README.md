## singleton-log
### A simple C++ logger that makes use of a singleton pattern

#### Installation
* Install cmake and make
* Build and install the library
```bash
cd /path/to/repo && cmake . && make install
```
* You should now have libsingleton-log.so in your default library location

#### Usage
Get an instance of the log
```CPP
Log* log = Log::getInstance();
```

Write to the log
```CPP
// Note that the message should be a std::string
log->write( Log::Level::INFO, "This is my message" );
log->write( Log::Level::ERR, "Oh no! An error has occurred!" );
```

Set log target (writes to STDOUT by default)
```CPP
// Set logger to write to the console
log->setTarget( Log::Target::STDOUT );

// Set logger to write to standard error
log->setTarget( Log::Target::STDERR );

// Set logger to write to a file
log->setTarget( Log::Target::LOG_FILE );
log->setFile( "myLog.log" );

// Set logger to write to the console and a file
log->setTarget( Log::Target::STDOUT | Log::Target::LOG_FILE );
log->setFile( "myLog.log" );
```

Set log level (Defaults to INFO). Only messages that are equal or more severe will be logged.
```CPP
// You can use any of the following log levels:
//	Log::Level::DEBUG,
//	Log::Level::INFO,
//	Log::Level::NOTICE,
//	Log::Level::WARNING,
//	Log::Level::ERR,
//	Log::Level::CRIT,
//	Log::Level::EMERG
log->setLevel( Log::Level::DEBUG );
```
