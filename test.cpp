#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "hash.cpp"

Hash h;
TEST_CASE("testing hash functions", "[h.function]"){
    REQUIRE(h.function("hello") == 32);
    REQUIRE(h.function("Water") == 15);
    REQUIRE(h.function("funtion") == 21);
    REQUIRE(h.function("treble") != 22);
    REQUIRE(h.function("tree") != 5);
    REQUIRE(h.function("Hamptons") != 43);
}
