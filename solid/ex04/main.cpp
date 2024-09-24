#include <iostream>
#include <vector>

#include "Header.hpp"
#include "Logger.hpp"

int main(void) {
    IHeader *hdr_custom = new ConstHeader("[super important garbage] ");
    IHeader *hdr_date   = new DateHeader();

    std::vector<ILogger *> loggers;
    loggers.push_back(new FileLogger("./log"));
    loggers.push_back(new HdrFileLogger("./log2", hdr_custom));
    loggers.push_back(new HdrFileLogger("./log3", hdr_date));
    loggers.push_back(new StreamLogger());
    loggers.push_back(new HdrStreamLogger(hdr_custom));
    loggers.push_back(new HdrStreamLogger(hdr_date));

    std::vector<std::string> logs;
    logs.push_back("arure arurow");
    logs.push_back("farofoso");
    logs.push_back("ConeMasters");

    std::vector<ILogger *>::iterator   it;
    std::vector<std::string>::iterator log;
    for (log = logs.begin(); log != logs.end(); ++log)
        for (it = loggers.begin(); it != loggers.end(); ++it) {
            (*it)->write(*log);
        }
    for (it = loggers.begin(); it != loggers.end(); ++it) {
        delete *it;
    };
    delete hdr_custom;
    delete hdr_date;
}
