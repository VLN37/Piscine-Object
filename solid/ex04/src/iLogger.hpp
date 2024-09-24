#pragma once

#include <string>

class ILogger {
 public:
    virtual ~ILogger() {}
    virtual void write(std::string str) = 0;
};
