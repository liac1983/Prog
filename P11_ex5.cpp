#include <iostream>
#include <vector>
#include <iomanip>
#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"

using namespace std;

virtual void HourlyEmployee::calculate_net_pay(){
     set_net_pay (wage_rate_ * hours_);
}
virtual void SalariedEmployee::calculate_net_pay(){
    set_net_pay (salary_);
}
virtual void read_hours_worked(vector<Employee*> &employees){
    for ( Employee* temp : employees){
        HourlyEmployee* worker = dynamic_cast<HourlyEmployee*>(temp); 
        if ( worker != nullptr){
            double temp2;
            cin >> temp2;
            worker->set_hours(temp2);
        }
    }
}
virtual void calculate_pay(vector<Employee*>& employees){
    for ( Employee* temp : employees){
        temp->calculate_net_pay();
    }
}
virtual void print_checks(const vector<Employee*>& employees){
    cout << "|";
    for ( Employee* temp : employees){
        cout << " ";
        HourlyEmployee* worker = dynamic_cast<HourlyEmployee*>(temp);
        if (worker != nullptr){
            cout <<fixed << setprecision(2)<< worker->get_name()<<":HE("
                << worker->get_hours()<<','
                <<worker->get_rate()<<")=" << worker->get_net_pay() << " |";
        }
        else{
            SalariedEmployee* worker = dynamic_cast<SalariedEmployee*>(temp);
            cout <<fixed << setprecision(2)<< worker->get_name()<< ":SE("<<
                    worker->get_salary()<< ")=" << 
                    worker->get_net_pay()<< " |";
        }
    }
}

int main() {
    vector<Employee*> employees = {
        new SalariedEmployee("John", 2000),
        new HourlyEmployee("Mary", 10) };
    read_hours_worked(employees);
    calculate_pay(employees);
    print_checks(employees);
    for (const auto& e : employees) delete e;
    return 0;
}