#include "catch.hpp"

#include "Common/BitVector.hpp"
#include "Common/Exception.hpp"

TEST_CASE("BitVector.getBitString", "[BitVector]") {
  SECTION("be the correct bit string") {
    const BitVector four(4);
    REQUIRE(four.getBitString() == "00000000000000000000000000000100");

    const BitVector thirtyTwo(32);
    REQUIRE(thirtyTwo.getBitString() == "00000000000000000000000000100000");

    const BitVector sixtyFive(65);
    REQUIRE(sixtyFive.getBitString() == "00000000000000000000000001000001");
  }
}

TEST_CASE("BitVector.getBit", "[BitVector]") {
  SECTION("be correct for certain inputs") {
    const BitVector four(4);
    REQUIRE_FALSE(four.getBit(0));
    REQUIRE(four.getBit(2));

    const BitVector thirtyTwo(32);
    REQUIRE_FALSE(thirtyTwo.getBit(0));
    REQUIRE(thirtyTwo.getBit(5));

    const BitVector sixtyFive(65);
    REQUIRE(sixtyFive.getBit(0));
    REQUIRE(sixtyFive.getBit(6));
    REQUIRE_FALSE(sixtyFive.getBit(2));
  }

  SECTION("throw an exception if position is invalid") {
    const BitVector four(4);
    REQUIRE_FALSE(four.getBit(0));
    REQUIRE_THROWS_AS(four.getBit(400), Exception);
  }
}
