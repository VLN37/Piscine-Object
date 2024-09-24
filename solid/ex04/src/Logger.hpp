#pragma once

#include <fstream>
#include <iostream>

#include "iHeader.hpp"
#include "iLogger.hpp"

class StreamLogger : public ILogger {
 public:
    StreamLogger() : o(std::cout) {}
    StreamLogger(std::ostream &o) : o(o) {}

    void write(std::string str) { o << str << std::endl; }

 protected:
    std::ostream &o;
};

class HdrStreamLogger : public StreamLogger {
 public:
    HdrStreamLogger(IHeader *header) : header(header) {}
    HdrStreamLogger(std::ostream &o, IHeader *header)
        : StreamLogger(o), header(header) {}

    void write(std::string str) {
        StreamLogger::write(std::string(header->output() + str));
    }

 protected:
    IHeader *header;
};

class FileLogger : public ILogger {
 public:
    ~FileLogger() { file.close(); }
    FileLogger(std::string filepath) {
        file.open(filepath.c_str(), std::fstream::out | std::fstream::trunc);
        if (file.bad()) {
            throw std::runtime_error("bad file");
        }
    }

    void write(std::string str) { file << str << std::endl; }

 protected:
    std::ofstream file;

 private:
    FileLogger() {};
};

class HdrFileLogger : public FileLogger {
 public:
    HdrFileLogger(std::string filepath, IHeader *header)
        : FileLogger(filepath), header(header) {}

    void write(std::string str) {
        FileLogger::write(std::string(header->output() + str));
    }

    IHeader *header;
};
