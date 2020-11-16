#include "catch.hpp"

#include "Shapes/Square.hpp"

TEST_CASE("Testing Square class", "[Square]") {
    SECTION("Using area should return the area of a square") {
        const Square test1(4);
        REQUIRE(static_cast<std::int32_t>(test1.area()) == 16);

        const Square test2;
        REQUIRE(static_cast<std::int32_t>(test2.area()) == 0);
    }

    SECTION("Using perimeter should return the perimeter of a square") {
        const Square test1(5);
        REQUIRE(static_cast<std::int32_t>(test1.perimeter()) == 20);

        const Square test2;
        REQUIRE(static_cast<std::int32_t>(std::round(test2.perimeter())) == 0);
    }
}
