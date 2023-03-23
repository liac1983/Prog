#include "Date.h"

// Default constructor
Date::Date(): year_(1), month_(1), day_(1) {}

// Constructor
Date::Date(int year, int month, int day): year_(year), month_(month), day_(day) {}

// Tell if the date is before the given date
bool Date::is_before(const Date& date) const {
    if(year_ < date.year_)
        return true;
    if(year_ == date.year_ && month_ < date.month_)
        return true;
    if(year_ == date.year_ && month_ == date.month_ && day_ < date.day_)
        return true;
    return false;
}