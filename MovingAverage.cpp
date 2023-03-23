#include "MovingAverage.h"
#include <iostream>
using namespace std;

MovingAverage::MovingAverage(size_t n){
    n_=n;
}
void MovingAverage::update(double value){
    if(values_.size()<n_){
        values_.push_back(value);
    }
    else{
        values_.push_back(value);
        values_.pop_front();
    }
}
double MovingAverage::get() const{
    double median=0;
    size_t number=0;
    size_t counter=0;
    for(double n: values_){
        if(number>=n_){break;}
        else{
            median+= n;
            number++;
            counter++;
        }
    }
    return median/number;
}

