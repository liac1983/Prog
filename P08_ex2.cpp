#include <iostream>
#include <iomanip>
#include "Date1.h"
 
using namespace std;

Date::Date(): year(1), month(1), day(1) {}
Date::Date(int year, int month, int day)
    : year(year), month(month), day(day) {}
int Date::get_year() const  {return year;}
int Date::get_month() const {return month;}
int Date:: get_day() const {return day;}

// external function
bool is_before(const Date& date1, const Date& date2) {
    int d1 = date1.get_year() *10000 + date1.get_month() * 100 + date1.get_day();
    int d2 = date2.get_year() * 10000 + date2.get_month() * 100 + date2.get_day();
    return d1 < d2;
}

int main() {
    Date d1; d1.write(); cout << '\n';
    return 0;
}