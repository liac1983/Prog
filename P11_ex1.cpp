#include <iostream>
#include "Person.h"

using namespace std;

#include <iostream>
#include "Person.h"

using namespace std;

class Student: public Person {
    public:
        Student(int id, const string& name, const string& course):
            Person(id, name), course_(course) {}
            const string& course() const { return course_;}
            string to_string() const { // override 
                return Person::to_string() + '/' + course_;
            }
    private:
        string course_;
};

class ErasmusStudent: public Student {
    public:
        ErasmusStudent(int id, const string& name, const string& course, const string& country):
Student(id, name, course), country_(country) {}
    const string& country() const {return country_;}
    string to_string() const {
        return Student::to_string() + '/' + country_;
    }
private:
    string country_;
};

int main() {
    const Person& p = Student(123, "Manuel Dias", "LEIC");
    cout << p.id() << ' ' << p.name() << '\n';
    return 0;
}