#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../../../practice/practice03/practice03.cpp"

TEST_CASE("sumRange works correctly", "[sumRange]") 
{
    REQUIRE(MathUtils::sumRange(1, 5) == 15);
    REQUIRE(MathUtils::sumRange(3, 3) == 3);
    REQUIRE(MathUtils::sumRange(-2, 2) == 0);
}

TEST_CASE("containsNegative behaves correctly", "[containsNegative]") 
{
    REQUIRE(MathUtils::containsNegative({ 1, 2, -3, 4 }) == true);
    REQUIRE(MathUtils::containsNegative({ 1, 2, 3, 4 }) == false);
    REQUIRE(MathUtils::containsNegative({}) == false);
}

TEST_CASE("findMax identifies the maximum value", "[findMax]") 
{
    REQUIRE(MathUtils::findMax({ 1, 2, 3 }) == 3);
    REQUIRE(MathUtils::findMax({ 3, 3, 3 }) == 3);
    REQUIRE(MathUtils::findMax({}) == INT_MIN);
}