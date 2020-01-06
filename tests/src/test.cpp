#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pqrs/cf/set.hpp>

TEST_CASE("make_empty_cf_set") {
  auto set = pqrs::cf::make_empty_cf_set();
  REQUIRE(set);
  REQUIRE(CFSetGetCount(*set) == 0);
}

TEST_CASE("make_cf_mutable_set") {
  auto set = pqrs::cf::make_cf_mutable_set();
  REQUIRE(set);
  REQUIRE(CFGetRetainCount(*set) == 1);
  REQUIRE(CFSetGetCount(*set) == 0);

  auto string1 = CFSTR("string1");
  auto string2 = CFSTR("string2");

  CFSetAddValue(*set, string1);
  CFSetAddValue(*set, string2);

  REQUIRE(CFSetGetCount(*set) == 2);
}
