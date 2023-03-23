#include <iostream>
#include <iomanip>
#include <sstream>
#include "Date3.h"

using namespace std;

Date::Date() : yyyymmdd("00010101") { }

Date::Date(int year, int month, int day) {
  if (year >= 1 && year <= 9999 &&
    month >= 1 && month <= 12 &&
    day >= 1 && day <= num_days(year, month))
  {
    std::ostringstream oss;
    oss << setfill('0') << setw(4) << year
      << setw(2) << month
      << setw(2) << day;
    yyyymmdd = oss.str();
  } 
  else {
    yyyymmdd = "00000000";
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
    std::ostringstream oss;
    oss << setfill('0') << setw(4) << year
      << setw(2) << month
      << setw(2) << day;
    yyyymmdd = oss.str();
  }
  else {
    yyyymmdd = "00000000";
  }
}

int Date::get_year() const {
  return stoi(yyyymmdd.substr(0, 4));
}

int Date::get_month() const {
  return stoi(yyyymmdd.substr(4, 2));
}

int Date::get_day() const {
  return stoi(yyyymmdd.substr(6, 2));
}

int Date::num_days(int year, int month) {
  int n_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    return 29;
  return n_days[month - 1];
}

bool Date::is_valid() const {
  return yyyymmdd != "00000000";
}

int main() {
    Date d1; d1.write(); cout << (d1.is_valid() ? "" : "-invalid") << endl;
    return 0;
}