#include "catch.hpp"

#include "Shapes/Circle.hpp"

TEST_CASE("Testing Circle class", "[Circle]") {
    SECTION("Using area should return the area of a circle") {
        const Circle test1(20);
        REQUIRE(static_cast<std::int32_t>(test1.area()) == 1256);

        const Circle test2;
        REQUIRE(static_cast<std::int32_t>(test2.area()) == 0);
    }

    SECTION("Using perimeter should return the perimeter of a circle") {
        const Circle test1(15);
        REQUIRE(static_cast<std::int32_t>(test1.perimeter()) == 94);

        const Circle test2;
        REQUIRE(static_cast<std::int32_t>(test2.perimeter()) == 0);
    }
}
