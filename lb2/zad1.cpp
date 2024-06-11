#include <iostream>
#include <format>
#include <cmath>
#include <vector>

double euclidean_norm(std::vector<double> &v) {
    double sum = 0.0f;
    for (auto &i : v) {
        sum += i * i;
    }
    return std::sqrt(sum);
}

double manhattan_norm(std::vector<double> &v) {
    double sum = 0.0f;
    for (auto &i : v) {
        sum += std::fabs(i);
    }
    return sum;
}

double maximum_norm(std::vector<double> &v) {
    double max = v[0];
    for (auto &i : v) {
        if (std::fabs(i) > max) {
            max = std::fabs(i);
        }
    }
    return max;
}

int main() {
    std::vector<double> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << std::format("Euclidean norm: {}\n", euclidean_norm(vec));
    std::cout << std::format("Manhattan norm: {}\n", manhattan_norm(vec));
    std::cout << std::format("Maximum norm: {}\n", maximum_norm(vec));
    return 0;
}
