#pragma once

#include <sstream>
#include <string>

std::string itoa(int i) {
    std::stringstream ss;
    std::string       result;

    ss << i;
    ss >> result;
    return result;
}
