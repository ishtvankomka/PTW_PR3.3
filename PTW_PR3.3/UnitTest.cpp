#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Student.cpp"
#include "Student.hpp"

TEST_CASE( "Arguments initialized") {
    Student *s1 = new Student[1];
    s1[0].physics = 2;
    s1[0].math = 3;
    s1[0].programming = 4;
    REQUIRE( getAverage(s1, 0) == 3);
}
