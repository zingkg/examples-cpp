#include "Common.hpp"

#include <sstream>

std::int64_t Common::parseInt(const char* string) {
    std::istringstream sStream(string);
    std::int64_t num;
    sStream >> num;
    return num;
}

std::int64_t Common::parseInt(const std::string &string) {
    return parseInt(string.c_str());
}

std::string Common::toString(const std::int16_t num) {
    std::ostringstream sStream;
    sStream << num;
    return sStream.str();
}

std::string Common::toString(const std::uint16_t num) {
    std::ostringstream sStream;
    sStream << num;
    return sStream.str();
}

std::string Common::toString(const std::int32_t num) {
    std::ostringstream sStream;
    sStream << num;
    return sStream.str();
}

std::string Common::toString(const std::uint32_t num) {
    std::ostringstream sStream;
    sStream << num;
    return sStream.str();
}

std::string Common::toString(const std::int64_t num) {
    std::ostringstream sStream;
    sStream << num;
    return sStream.str();
}

std::string Common::toString(const std::uint64_t num) {
    std::ostringstream sStream;
    sStream << num;
    return sStream.str();
}
