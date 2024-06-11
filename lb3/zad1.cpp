#include <iostream>
#include <format>
#include <cmath>
#include <vector>

typedef std::vector<std::vector<double>> matrix_t;

double matrix_det(matrix_t m) {
    if (m.size() == 1) {
        return m[0][0];
    }

    double det = 0;

    for (size_t i = 0; i < m.size(); i++) {
        matrix_t m_new;

        for (size_t j = 1; j < m.size(); j++) {
            std::vector<double> row;

            for (size_t k = 0; k < m.size(); k++) {
                if (k != i) {
                    row.push_back(m[j][k]);
                }
            }

            m_new.push_back(row);
        }

        det += m[0][i] * pow(-1, i) * matrix_det(m_new);
    }

    return det;
}

int main() {
    matrix_t m1 = {
        {7}
    };

    matrix_t m2 = {
        {1, 2},
        {3, 4}
    };

    matrix_t m3 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    matrix_t m4 = {
        {1, 3, 7, 2},
        {3, 0, 0, 0},
        {1, -1, -1, 2},
        {3, 8, 5, 4}
    }; // -312

    std::cout << "det(m1) = " << matrix_det(m1) << "\n";
    std::cout << "det(m2) = " << matrix_det(m2) << "\n";
    std::cout << "det(m3) = " << matrix_det(m3) << "\n";
    std::cout << "det(m4) = " << matrix_det(m4) << "\n";
    return 0;
}
