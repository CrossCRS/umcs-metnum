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

// nope
matrix_t matrix_inverse(const matrix_t &m) {
    matrix_t m_result;

    double det = matrix_det(m);
    if (det == 0) {
        std::cerr << "det is 0!\n";
        return m_result;
    }

    m_result = matrix_transpose(m);

    for (size_t i = 0; i < m_result.size(); i++) {
        for (size_t j = 0; j < m_result[i].size(); j++) {
            m_result[i][j] *= pow(-1, i + j) * matrix_det(m_result) / det;
        }
    }

    return m_result;
}

void matrix_print(const matrix_t &m) {
    for (size_t i = 0; i < m.size(); i++) {
        for (size_t j = 0; j < m[i].size(); j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    matrix_t m1 = {
        {1, 2, 3},
        {0, 1, 2},
        {2, 1, 1}
    };

    matrix_print(m1);
    std::cout << "\n";
    matrix_print(matrix_inverse(m1));

    return 0;
}
