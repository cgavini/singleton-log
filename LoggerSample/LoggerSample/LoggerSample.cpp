// LoggerSample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <string>
#include "../../LogUtil.h"
using namespace bf;


std::string getThreadId()
{
	std::thread::id thd_id = std::this_thread::get_id();
    std::stringstream ss;
    ss << thd_id;
    return ss.str();
}

void helloFromThread()
{
    auto log = LogUtil::getFileLogger("MyLog.log");
    log->write(Log::Level::INFO, __FUNCTION__ + std::string(" Thread ") + getThreadId() + std::string(" Hello "));

}

int main()
{
	std::thread::id main_thread_id = std::this_thread::get_id();

	auto log = LogUtil::getFileLogger("MyLog.log");
	std::stringstream ss;
	ss << main_thread_id;
	log->write(Log::Level::INFO,__FUNCTION__ + std::string(" Thread ") + getThreadId()+ std::string(" Hello World"));

    std::thread t1([] {
        helloFromThread();
        });
    std::thread t2([] {
        helloFromThread();
        });
    t1.join();
    t2.join();

    return 0;
}

