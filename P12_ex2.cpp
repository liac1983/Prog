#include <iostream>
#include <iomanip>
#include "Student.h"

using namespace std;

Student::Student(const std::string& name, const std::string& id, short ac, short p1, short p2){
              name_ = name;
              id_ = id;
              ac_ = ac;
              p1_ = p1;
              p2_ = p2;
          }

string Student::get_id() const {
    return id_;
}

string Student::get_name() const {
    return name_;
}

double Student::actual_grade() const {
    return (0.1*ac_) + (0.45*p1_) + (0.45*p2_);
}

int main() {
    Student s("Andre Meira", "up201404877", 20, 18, 10);
    cout << "[" << s.get_id() << "]" << "/";
    cout << fixed << setprecision(2) << s.actual_grade() << endl;
    return 0;
}