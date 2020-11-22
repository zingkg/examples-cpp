#include "catch.hpp"

#include "Common/Exception.hpp"

TEST_CASE("Testing Exception Class", "[Exception]") {
  SECTION("Testing exception") {
    REQUIRE(std::string(Exception("exception string")) == "exception string");
    REQUIRE(
      std::string(Exception("Hi", __FILE__, __LINE__)) == (std::string("Hi occurred in ")) +
        __FILE__ + std::string(" on line ") + Common::toString(__LINE__)
    );
  }
}
