#include <iostream>
#include <iomanip>

int main(){
    int k;
    int d;
    std::cout << "k:" << "d:";
    std::cin >> k >> d;
    double approx = 0;
    for (int i  = 0; i <= k; i++){
        double term = 1.0/ (2 * i + 1);
        approx += i % 2 == 0 ? term : -term;
    }
    approx *= 4;
    std::cout << std::fixed << std::setprecision(d) << approx << std::endl;
    return 0;
}