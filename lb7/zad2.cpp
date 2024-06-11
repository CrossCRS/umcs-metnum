#include <cstdio>
#include <iostream>
#include <vector>

double linear_interp(std::vector<double> x, std::vector<double> y, double p) {
    double sum = 0.0;

    std::vector<std::vector<double>> diff_quotients;

    // popsute straszliwie
    diff_quotients.resize(y.size());

    for (size_t i = 0; i < y.size(); i++) {
        diff_quotients[i] = std::vector<double>();
        diff_quotients[i].resize(y.size());

        diff_quotients[i][0] = y[i];
    }

    for (size_t i = 0; i < y.size(); i++) {
        for (size_t j = 1; j < y.size(); j++) {
            diff_quotients[i][j] = (diff_quotients[i][j - 1] - diff_quotients[j - 1][j - 1]) / (x[i] - x[j - 1]);
        }
    }

    for (size_t i = 0; i < y.size(); i++) {
        double r = diff_quotients[0][i];

        for (size_t j = 0; j < x.size(); j++) {
            r *= (p - x[j]);
        }

        sum += r;
    }

    return sum;
}

int main() {
    std::vector<double> x = { -1.4, -1, 0, 1, 2, 2.2, 2.5, 2.7, 3, 3.2 };
    std::vector<double> y = { 11.95, 1.85, 1.0, 0.54, 0.17, 0.31, 0.57, 0.76, 0.97, 0.99 };

    printf("f(1.5) = %.6f\n", linear_interp(x, y, 1.5));

    return 0;
}
