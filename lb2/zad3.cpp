#include <iostream>
#include <format>
#include <cmath>
#include <vector>

double max_norm(std::vector<std::vector<double>> &matrix_t) {
    double max = matrix_t[0][0];

    for (auto &r : matrix_t) {
        for (auto &el : r) {
            if (el > max) {
                max = el;
            }
        }
    }

    return max;
}

int main() {
    int n = 4;
    int m = 4;

    std::vector<std::vector<double>> matrix_t;
    matrix_t.resize(m);
    for (auto &r : matrix_t) {
        r.resize(n);
    }
    return 0;
}
