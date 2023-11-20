#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Gregorian.h"

TEST_CASE("ExampleDate"){
    GregorianDate gregDate;
    gregDate.SetMonth(12);
    gregDate.SetDay(2);
    gregDate.SetYear(2020);
    CHECK(gregDate.getAbsoluteDate() == 737761);
}


TEST_CASE("IncorrectDate"){
    GregorianDate gregDate;
    gregDate.SetMonth(12);
    gregDate.SetDay(0);
    gregDate.SetYear(2020);
    REQUIRE(gregDate.getAbsoluteDate() == 0);
}