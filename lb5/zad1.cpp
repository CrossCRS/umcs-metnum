#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>

typedef std::vector<std::vector<double>> matrix_t;

void print(const matrix_t &m) {
    for (size_t i = 0; i < m.size(); i++) {
        for (size_t j = 0; j < m[i].size(); j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void print(const std::vector<double> &a) {
    for (size_t i = 0; i < a.size(); i++) {
        printf("%.16f ", a[i]);
    }
    std::cout << "\n";
}

double max_norm(const std::vector<double> &a) {
    double max = a[0];

    for (size_t i = 1; i < a.size(); i++) {
        if (a[i] > max)
            max = a[i];
    }

    return max;
}

std::vector<double> jacobi_a(const matrix_t &a, const std::vector<double> &b, int k) {
    std::vector<double> x(b.size(), 0);

    for (int iter = 0; iter < k; iter++) {
        for (size_t i = 0; i < x.size(); i++) {
            double sum = 0;

            for (size_t j = 0; j < a.size(); j++) {
                if (j == i) continue;

                sum += a[i][j] * x[j];
            }

            x[i] = (b[i] - sum) / a[i][i];
        }
    }

    return x;
}

std::vector<double> jacobi_b(const matrix_t &a, const std::vector<double> &b, double ep) {
    std::vector<double> x(b.size(), 0);
    std::vector<double> last_x(b.size(), 0);

    double x_norm;
    double last_x_norm;

    do {
        for (size_t i = 0; i < x.size(); i++) {
            // double sum = 0;

            // for (size_t j = 0; j < a.size(); j++) {
            //     if (j == i) continue;

            //     sum += a[i][j] * x[j];
            // }
            double sum1 = 0;
            double sum2 = 0;

            for (size_t j = 0; j < i-1; j++) {
                sum1 += a[i][j] * x[j];
            }

            for (size_t j = i + 1; j < a.size(); j++) {
                sum2 += a[i][j] * last_x[j];
            }

            x[i] = (b[i] - sum1 - sum2) / a[i][i];
        }

        x_norm = max_norm(x);
        last_x_norm = max_norm(last_x);

        last_x = x;
        print(x);
    } while (((x_norm - last_x_norm) / x_norm) >= ep);

    return x;
}

int main() {
    matrix_t a = {{  4, -2,  0,  0 },
                  { -2,  5, -1,  0 },
                  {  0, -1,  4,  2 },
                  {  0,  0,  2,  3 }};

    std::vector<double> b = { 0, 2, 3, -2 };

    // std::vector<double> x = jacobi_a(a, b, 100);
    // std::vector<double> x = jacobi_b(a, b, 1.0e-7);

    // print(x);

    // printf("epsilon = 1.0e-6\n");
    // print(jacobi_b(a, b, 1.0e-6));

    printf("\nepsilon = 1.0e-16\n");
    print(jacobi_b(a, b, 1.0e-16));
    return 0;
}
