## singleton-log
### A simple C++ logger that makes use of a singleton pattern

#### Installation
* This library can be installed with cmake and make (cd path/to/repo && cmake . && make). This step isn't necessary because I keep a pre-built .so in the repo.
* Then include the repo path in your compiler's include path or move the .so to a folder that's already in the include path.

#### Usage
Get an instance of the log
```CPP
Log* log = Log::getLog();
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

// Set logger to write to a file
log->setTarget( Log::Target::LOG_FILE );
log->setLogFile( "myLog.log" );

// Set logger to write to console and a file
log->setTarget( Log::Target::STDOUT | Log::Target::LOG_FILE );
log->setLogFile( "myLog.log" );
```

Set log level. Only messages that are equal or more severe will be logged.
```CPP
// There are 3 log levels available currently: DEBUG, INFO, and ERR
log->setLogLevel( Log::Level::DEBUG );
log->setLogLevel( Log::Level::INFO );
log->setLogLevel( Log::Level::ERR );
```
