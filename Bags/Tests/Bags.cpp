#include "catch.hpp"

#include "Bags/Bags.hpp"

TEST_CASE("Bags", "[Bags]") {
  const std::vector<uint16_t> bags25 {
    16,
    24,
    25,
    3,
    20,
    18,
    7,
    17,
    4,
    15,
    13,
    22,
    2,
    12,
    10,
    5,
    8,
    1,
    11,
    21,
    19,
    6,
    23,
    9,
    14
  };

  const std::vector<uint16_t> expectedSeven {
    6,
    23,
    9,
    14,
    10,
    5,
    8,
    1,
    11,
    21,
    19,
    17,
    4,
    15,
    13,
    22,
    2,
    12,
    16,
    24,
    25,
    3,
    20,
    18,
    7
  };
  const std::vector<uint16_t> expectedTen {
    19,
    6,
    23,
    9,
    14,
    13,
    22,
    2,
    12,
    10,
    5,
    8,
    1,
    11,
    21,
    16,
    24,
    25,
    3,
    20,
    18,
    7,
    17,
    4,
    15
  };

  SECTION("weissBags") {
    const std::vector<uint16_t> actualSeven = Bags::weissBags(bags25, 7);
    REQUIRE(actualSeven == expectedSeven);

    const std::vector<uint16_t> actualTen = Bags::weissBags(bags25, 10);
    REQUIRE(actualTen == expectedTen);
  }

  SECTION("stlBags") {
    const std::vector<uint16_t> actualSeven = Bags::stlBags(bags25, 7);
    REQUIRE(actualSeven == expectedSeven);

    const std::vector<uint16_t> actualTen = Bags::stlBags(bags25, 10);
    REQUIRE(actualTen == expectedTen);
  }

  SECTION("stlFunctionalBags") {
    const std::vector<uint16_t> actualSeven = Bags::stlFunctionalBags(bags25, 7);
    REQUIRE(actualSeven == expectedSeven);

    const std::vector<uint16_t> actualTen = Bags::stlFunctionalBags(bags25, 10);
    REQUIRE(actualTen == expectedTen);
  }
}
