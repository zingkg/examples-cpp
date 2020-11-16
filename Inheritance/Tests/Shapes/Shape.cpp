#include "catch.hpp"

#include "Shapes/Circle.hpp"
#include "Shapes/Rectangle.hpp"

#include <memory>

TEST_CASE("Testing Shape class", "[Shape]") {
    SECTION("A rectangle shape should execute the correct area function") {
        std::unique_ptr<Shape> ptr(new Rectangle(30, 50));
        REQUIRE(static_cast<std::int32_t>(ptr->area()) == 1500);

        ptr.reset(new Circle(20));
        REQUIRE(static_cast<std::int32_t>(ptr->area()) == 1256);
    }

    SECTION("Using perimeter should execute correct perimeter function") {
        std::unique_ptr<Shape> ptr(new Rectangle(2, 4));
        REQUIRE(static_cast<std::int32_t>(ptr->perimeter()) == 12);

        ptr.reset(new Circle(5));
        REQUIRE(static_cast<std::int32_t>(ptr->perimeter()) == 31);
    }
}
