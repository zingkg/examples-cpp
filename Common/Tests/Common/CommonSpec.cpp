#include "catch.hpp"

#include "Common/Common.hpp"

#include <cstdint>

TEST_CASE("Testing Common", "[Common]") {
    SECTION("parse int should parse a string correctly and return its integer value") {
        SECTION("it should parse a const string literal correctly") {
            REQUIRE(Common::parseInt("55") == 55);
            REQUIRE(Common::parseInt("55.9") == 55);
        }

        SECTION("it should parse a string class correctly") {
            REQUIRE(Common::parseInt(std::string("90")) == 90);
            REQUIRE(Common::parseInt(std::string("90.5")) == 90);
        }
    }

    SECTION("Testing to string") {
        REQUIRE(Common::toString(5) == "5");
        REQUIRE(Common::toString(std::numeric_limits<int64_t>::min()) == "-9223372036854775808");
        REQUIRE(Common::toString(std::numeric_limits<int64_t>::max()) == "9223372036854775807");
        REQUIRE(Common::toString(std::numeric_limits<uint64_t>::min()) == "0");
        REQUIRE(Common::toString(std::numeric_limits<uint64_t>::max()) == "18446744073709551615");
    }
}
