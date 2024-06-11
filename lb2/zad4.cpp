#include <iostream>
#include <format>
#include <cmath>
#include <vector>

typedef std::vector<std::vector<double>> matrix_t;

matrix_t matrix_mult(matrix_t &mat1, matrix_t &mat2) {
    matrix_t result;

    size_t n1 = mat1.size();
    size_t m1 = mat1[0].size();

    size_t n2 = mat2.size();
    size_t m2 = mat2[0].size();

    if (m1 != n2) {
        std::cerr << "Niekompatybilne rozmiary macierzy!\n";
    }

    return result;
}

int main() {
    matrix_t m1 = {
        {1, 2, 3},
        {4, 5, 6}
    };

    matrix_t m2 = {
        {1, 2},
        {3, 4},
        {5, 6}
    };

    return 0;
}
