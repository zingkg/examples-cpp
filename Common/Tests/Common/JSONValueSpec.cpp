#include "catch.hpp"

#include "Common/Common.hpp"
#include "Common/JSONValue.hpp"

TEST_CASE("Testing JSONValue class", "[JSONValue]") {
  SECTION("Testing default constructor") {
    const JSONValue blank;
    REQUIRE("null" == blank.getValue());
  }

  SECTION("Testing copy constructor") {
    const JSONValue boolean(true);
    const JSONValue copy(boolean);
    REQUIRE("true" == boolean.getValue());
    REQUIRE(boolean.getValue() == copy.getValue());
  }

  SECTION("Testing boolean constructor") {
    REQUIRE("true" == JSONValue(true).getValue());
    REQUIRE("false" == JSONValue(false).getValue());
  }

  SECTION("Testing int32_t constructor") {
    REQUIRE("100" == JSONValue(100).getValue());
  }

  SECTION("Testing int64_t constructor") {
    const int64_t longNumber = 91240718946184;
    REQUIRE(Common::toString(longNumber) == JSONValue(longNumber).getValue());
  }

  SECTION("Testing const char* constructor") {
    REQUIRE("\"abcdefg\"" == JSONValue("abcdefg").getValue());
  }
}
