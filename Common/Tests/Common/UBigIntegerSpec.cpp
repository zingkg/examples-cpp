#include "catch.hpp"

#include "Common/UBigInteger.hpp"

TEST_CASE("Testing UBigInteger class", "[UBigInteger]") {
  SECTION("Default constructor") {
    REQUIRE("0" == std::string(UBigInteger()));
  }

  SECTION("uint32_t constructor") {
    REQUIRE("45" == std::string(UBigInteger(45)));
  }

  SECTION("Testing add function") {
    const UBigInteger add1(5);
    REQUIRE(std::string(add1 + 5) == "10");
    REQUIRE(std::string(add1 + UBigInteger(5)) == "10");

    const UBigInteger add2(75);
    REQUIRE(std::string(add2 + 2025) == "2100");
    REQUIRE(std::string(add2 + UBigInteger(2025)) == "2100");

    const UBigInteger add3(105);
    REQUIRE(std::string(add3 + 5) == "110");

    const UBigInteger add4(18446744073709551615UL);
    REQUIRE(std::string(add4 + 5) == "18446744073709551620");
  }

  SECTION("Testing subtract function") {
    const UBigInteger sub1(10);
    REQUIRE(std::string(sub1 - 5) == "5");
    REQUIRE(std::string(sub1 - UBigInteger(5)) == "5");

    const UBigInteger sub2(100);
    REQUIRE(std::string(sub2 - 95) == "5");
    REQUIRE(std::string(sub2 - UBigInteger(95)) == "5");

    const UBigInteger sub3(92);
    REQUIRE(std::string(sub3 - 13) == "79");
    REQUIRE(std::string(sub3 - UBigInteger(13)) == "79");

    const UBigInteger sub4(5);
    REQUIRE(std::string(sub4 - 5) == "0");
    REQUIRE(std::string(sub4 - UBigInteger(5)) == "0");

    const UBigInteger sub5(100);
    REQUIRE(std::string(sub5 - 3) == "97");
    REQUIRE(std::string(sub5 - UBigInteger(3)) == "97");
  }

  SECTION("Testing multiply function") {
    const UBigInteger mult1(2);
    REQUIRE(std::string(mult1 * 2) == "4");
    REQUIRE(std::string(mult1 * UBigInteger(2)) == "4");

    const UBigInteger mult2(5);
    REQUIRE(std::string(mult2 * 5) == "25");
    REQUIRE(std::string(mult2 * UBigInteger(5)) == "25");
  }

  SECTION("Testing divide function") {
    const UBigInteger div1(5);
    REQUIRE(std::string(div1 / 2) == "2");
    REQUIRE(std::string(div1 / UBigInteger(2)) == "2");

    const UBigInteger div2(10);
    REQUIRE(std::string(div2 / 2) == "5");
    REQUIRE(std::string(div2 / UBigInteger(2)) == "5");

    const UBigInteger div3(100);
    REQUIRE(std::string(div3 / 3) == "33");
    REQUIRE(std::string(div3 / UBigInteger(3)) == "33");
  }

  SECTION("Testing modulus function") {
    const UBigInteger mod1(5);
    REQUIRE(std::string(mod1 % 2) == "1");
    REQUIRE(std::string(mod1 % UBigInteger(2)) == "1");

    const UBigInteger mod2(10);
    REQUIRE(std::string(mod2 % 2) == "0");
    REQUIRE(std::string(mod2 % UBigInteger(2)) == "0");

    const UBigInteger mod3(100);
    REQUIRE(std::string(mod3 % 3) == "1");
    REQUIRE(std::string(mod3 % UBigInteger(3)) == "1");
  }

  SECTION("operator==") {
    REQUIRE(UBigInteger(5) == UBigInteger(5));
    REQUIRE(UBigInteger(10) == UBigInteger(5) + 5);
  }

  SECTION("operator<") {
    REQUIRE(UBigInteger(5) < UBigInteger(6));
    REQUIRE(UBigInteger(100) < UBigInteger(101));
    REQUIRE_FALSE(UBigInteger(1100) < UBigInteger(1100));
  }

  SECTION("operator>") {
    REQUIRE(UBigInteger(6) > UBigInteger(5));
    REQUIRE(UBigInteger(101) > UBigInteger(100));
    REQUIRE_FALSE(UBigInteger(1100) > UBigInteger(1100));
  }
}
