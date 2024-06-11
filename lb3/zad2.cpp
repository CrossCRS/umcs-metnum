#include <iostream>
#include <format>
#include <cmath>
#include <vector>

typedef std::vector<std::vector<double>> matrix_t;

void matrix_print(const matrix_t &m) {
    for (size_t i = 0; i < m.size(); i++) {
        for (size_t j = 0; j < m[i].size(); j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }
}

matrix_t matrix_transpose(const matrix_t &m) {
    matrix_t result;

    for (size_t i = 0; i < m[0].size(); i++) {
        std::vector<double> row;

        for (size_t j = 0; j < m.size(); j++) {
            row.push_back(m[j][i]);
        }

        result.push_back(row);
    }

    return result;
}

int main() {
    matrix_t m1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    matrix_print(m1);
    std::cout << "\n";
    matrix_print(matrix_transpose(m1));

    return 0;
}
