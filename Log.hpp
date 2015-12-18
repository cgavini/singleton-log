#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <ctime>

using std::string;
using std::map;
using std::cout;
using std::endl;
using std::ofstream;

class Log {
	public:
		enum class Target : short {
			STDOUT = 1,
			LOG_FILE = 2
		};

		enum class Level : short {
			DEBUG = 1,
			INFO = 2,
			ERR = 3
		};

		/**
		 * Get singleton instance.
		 *
		 * \return	Log*	Pointer to Log instance
		 */
		static Log* getLog();

		/**
		 * Set the location to log messages.
		 *
		 * \param	Target	The log target
		 */
		void setTarget( Target target );

		/**
		 * Set a file to log to if the target is LOG_FILE.
		 *
		 * \param	string	The file to which we will log
		 */
		int setLogFile( string fileName );

		/**
		 * Get the current log level. Only messages
		 * with equal or higher severity will be written.
		 *
		 * \return	Log::Level	The current log level
		 */
		Level getLogLevel();

		/**
		 * Convert the Log::Level enum to a string.
		 *
		 * \param	Log::Level	The level to convert
		 * \return	string	The converted level
		 */
		string logLevelToString( Level level );

		/**
		 * Log a message.
		 *
		 * \param	Level	The severity of the message
		 * \param	string	The message to write
		 */
		void write( Level level, string message );

		/**
		 * Date and time will no longer be printed with each log message.
		 */
		void excludeTimestamp() {
			this->timestampEnabled = false;
		}
		
		/**
		 * Date and time will be printed with each log message.
		 */
		void includeTimestamp() {
			this->timestampEnabled = true;
		}

		/**
		 * Log level will no longer be printed with each log message.
		 */
		void excludeLogLevel() {
			this->levelEnabled = false;
		}
		
		/**
		 * Log level will be printed with each log message.
		 */
		void includeLogLevel() {
			this->levelEnabled = true;
		}

	protected:
		Log() {}

	private:
		// Our single instance of the class
		static Log* log;

		// Enums that tell write() what and where to log
		Target logTarget = Target::STDOUT;
		Level logLevel = Level::DEBUG;

		// Flags that change log style
		bool timestampEnabled = true;
		bool levelEnabled = true;

		// Where to print if using the LOG_FILE target
		string logFile = "";

		// String representations of log levels
		map< Level, string > levelMap = {
			{ Level::DEBUG, "DEBUG" },
			{ Level::INFO, "INFO" },
			{ Level::ERR, "ERROR" }
		};
};
