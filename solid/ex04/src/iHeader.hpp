#pragma once

class IHeader {
 public:
    virtual ~IHeader() {};
    virtual const char *output() = 0;
};
