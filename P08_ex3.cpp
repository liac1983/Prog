#include <iostream>
#include <iomanip>
#include <sstream>

#include "Date2.h"

using namespace std;

Date::Date() : year(1), month(1), day(1) { }

Date::Date(int year, int month, int day) {
  if (year >= 1 && year <= 9999 &&
    month >= 1 && month <= 12 && 
    day >= 1 && day <= num_days(year, month))
    {
      this -> year = year;
      this -> month = month;
      this -> day = day;
    } else {
      this -> year = 0;
      this -> month = 0;
      this -> day = 0; 
    }
}

Date::Date(const string& year_month_day) {
  int year, month, day;
  char sep1, sep2;

  istringstream iss(year_month_day);
  if (iss >> year >> sep1 >> month >> sep2 >> day
    && sep1 == '/' && sep2 == '/'
    && year >= 1 && year <= 9999
    && month >= 1 && month <= 12
    && day >= 1 && day <= num_days(year, month))
    {
      this -> year = year;
      this -> month = month,
      this -> day = day;
    } else {
      this -> year = 0;
      this -> month = 0;
      this -> day = 0;
    }
}

int Date::get_year() const {
  return year;
}

int Date::get_month() const {
  return month;
}

int Date::get_day() const {
  return day;
}

int Date::num_days(int year, int month) {
  int n_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month == 2 && year % 4 ==0 && (year % 100 != 0 || year % 400 == 0))
    return 29;
  return n_days[month - 1];
}

bool Date::is_valid() const {
  return year != 0 && month != 0 && day != 0;
}

int main() {
  	
Date d1; d1.write(); cout << (d1.is_valid() ? "" : "-invalid") << endl;
  return 0;
}
