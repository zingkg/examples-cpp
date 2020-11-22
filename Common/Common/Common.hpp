#ifndef COMMON_HPP
#define COMMON_HPP

#include <cstdint>
#include <string>

class Common {
public:
    static std::int64_t parseInt(const char* string);

    static std::int64_t parseInt(const std::string &string);

    static std::string toString(const std::int16_t num);

    static std::string toString(const std::uint16_t num);

    static std::string toString(const std::int32_t num);

    static std::string toString(const std::uint32_t num);

    static std::string toString(const std::int64_t num);

    static std::string toString(const std::uint64_t num);
};

#endif // COMMON_HPP
