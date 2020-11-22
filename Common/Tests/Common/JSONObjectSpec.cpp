#include "catch.hpp"

#include "Common/JSONObject.hpp"

TEST_CASE("Testing JSONObject class", "[JSONObject]") {
  SECTION("Testing default constructor") {
    JSONObject def;
    REQUIRE(def.toString() == "");
  }

  SECTION("Testing copy constructor") {
    JSONObject obj1;
    obj1.putValue("hi", "hello");
    obj1.putValue("bool1", true);
    const JSONObject copy(obj1);
    REQUIRE(copy.toString() == "{\"bool1\":true,\"hi\":\"hello\"}");
  }

  SECTION("Testing putValue on bool") {
    JSONObject bools;
    bools.putValue("bool1", true);
    bools.putValue("bool2", false);
    REQUIRE(bools.toString() == "{\"bool1\":true,\"bool2\":false}");
  }

  SECTION("Testing putValue on int32_t") {
    JSONObject ints;
    ints.putValue("num1", 5);
    ints.putValue("num2", 6);
    REQUIRE(ints.toString() == "{\"num1\":5,\"num2\":6}");
  }

  SECTION("Testing putValue on int64_t") {
    JSONObject int64s;
    int64s.putValue("num1", 983957832758927358);
    int64s.putValue("num2", 8475834534534534);
    REQUIRE(int64s.toString() == "{\"num1\":983957832758927358,\"num2\":8475834534534534}");
  }

  SECTION("Testing putValue on string") {
    JSONObject strings;
    strings.putValue("str1", "blah");
    strings.putValue("str2", "pink");
    REQUIRE(strings.toString() == "{\"str1\":\"blah\",\"str2\":\"pink\"}");
  }

  SECTION("Testing putValue on objects") {
    JSONObject strings;
    strings.putValue("str1", "blah");
    strings.putValue("str2", "pink");
    JSONObject full;
    full.putValue("obj1", strings);
    full.putValue("bool", true);
    full.putValue("num2", 123);
    REQUIRE(full.toString() == "{\"bool\":true,\"num2\":123,\"obj1\":{\"str1\":\"blah\",\"str2\":\"pink\"}}");
  }
}
