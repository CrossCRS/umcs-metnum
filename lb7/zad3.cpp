#include <cstdio>
#include <iostream>
#include <vector>

double linear_interp(std::vector<double> x, std::vector<double> y, double p) {
    double sum = 0.0;



    return sum;
}

int main() {
    std::vector<double> x = { -1.4, -1, 0, 1, 2, 2.2, 2.5, 2.7, 3, 3.2 };
    std::vector<double> y = { 11.95, 1.85, 1.0, 0.54, 0.17, 0.31, 0.57, 0.76, 0.97, 0.99 };

    printf("f(1.5) = %.6f\n", linear_interp(x, y, 1.5));

    return 0;
}
