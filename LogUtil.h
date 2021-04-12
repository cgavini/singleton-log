#pragma once
#include <string>
#include "Log.hpp"
class LogUtil
{ 
public:
	static std::shared_ptr<bf::Log> getFileLogger(std::string logFileName)
	{
		using namespace bf;
		auto log = bf::Log::getInstance();
		log->setTarget(Log::Target::LOG_FILE);
		log->setFile(logFileName);
		return log;
	}
};

