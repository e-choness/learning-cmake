#include "doctest.h"

#include "Gregorian.h"
#include "Julian.h"

TEST_CASE("Check various dates"){
    GregorianDate greDate;
    JulianDate julDate;

    SUBCASE("Gregorian 1/1/1 -> Julian 1/3/1"){
        greDate.SetMonth(1);
        greDate.SetDay(1);
        greDate.SetYear(1);

        auto absGregDate = greDate.getAbsoluteDate();
        julDate.CalcJulianDate(absGregDate);

        CHECK(julDate.getMonth() == 1);
        CHECK(julDate.getDay() == 3);
        CHECK(julDate.getYear() == 1);
    }

    SUBCASE("Gregorian 3/1/100 -> Julian 3/2/100"){
        greDate.SetMonth(3);
        greDate.SetDay(1);
        greDate.SetYear(100);

        auto absGregDate = greDate.getAbsoluteDate();

        julDate.CalcJulianDate(absGregDate);

        CHECK(julDate.getMonth() == 3);
        CHECK(julDate.getDay() == 2);
        CHECK(julDate.getYear() == 100);
    }

    SUBCASE("Gregorian 3/1/300 -> Julian 2/29/300"){
        greDate.SetMonth(3);
        greDate.SetDay(1);
        greDate.SetYear(300);

        auto absGregDate = greDate.getAbsoluteDate();
        julDate.CalcJulianDate(absGregDate);

        CHECK(julDate.getMonth() == 2);
        CHECK(julDate.getDay() == 29);
        CHECK(julDate.getYear() == 300);
    }

    SUBCASE("Gregorian 3/1/900 - Julian 2/25/900"){
        greDate.SetMonth(3);
        greDate.SetDay(1);
        greDate.SetYear(900);

        auto absGregDate = greDate.getAbsoluteDate();
        julDate.CalcJulianDate(absGregDate);

        CHECK(julDate.getMonth() == 2);
        CHECK(julDate.getDay() == 25);
        CHECK(julDate.getYear() == 900);
    }
}