#include "catch.hpp"

#include "Inheritance/Rectangle.hpp"

TEST_CASE("Testing Rectangle class", "[Rectangle]") {
    SECTION("Using area should return the area of a rectangle") {
        const Rectangle test1(4, 6);
        REQUIRE(static_cast<std::int32_t>(test1.area()) == 24);

        const Rectangle test2;
        REQUIRE(static_cast<std::int32_t>(test2.area()) == 0);
    }

    SECTION("Using perimeter should return the perimeter of a rectangle") {
        const Rectangle test1(5, 10);
        REQUIRE(static_cast<std::int32_t>(test1.perimeter()) == 30);

        const Rectangle test2;
        REQUIRE(static_cast<std::int32_t>(test2.perimeter()) == 0);
    }
}
