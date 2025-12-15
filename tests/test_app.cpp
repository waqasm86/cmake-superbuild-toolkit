#include "myapp/app.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("join_with_commas works") {
  REQUIRE(myapp::join_with_commas({}) == "");
  REQUIRE(myapp::join_with_commas({"a"}) == "a");
  REQUIRE(myapp::join_with_commas({"a","b","c"}) == "a,b,c");
}

TEST_CASE("info returns platform string") {
  const auto i = myapp::info();
  REQUIRE_FALSE(i.platform.empty());
}
