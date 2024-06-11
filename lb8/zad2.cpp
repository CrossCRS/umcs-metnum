#include <cstdio>
#include <cmath>
#include <chrono>

using namespace std::chrono;

double factorial(double n) {
    if (n == 1 || n == 0) {
        return 1;
    }

    return factorial(n - 1) * n;
}

double maclaurin_sin(double x, double e) {
    double result = 0;
    double term = 0;
    int i = 0;

    do {
        term = (pow(-1, i) / factorial(2 * i + 1)) * pow(x, 2 * i + 1);
        result += term;
        i++;
    } while (fabs(term) > e);

    return result;
}

int main() {
    auto start = high_resolution_clock::now();
    printf("sin(pi/2) (maclaurin) = %.16f\n", maclaurin_sin(M_PI / 2, pow(10, -8)));
    auto stop = high_resolution_clock::now();
    printf("Time: %ldms\n\n", duration_cast<microseconds>(stop - start).count());

    start = high_resolution_clock::now();
    printf("sin(pi/2) (stdlib) = %.16f\n", sin(M_PI / 2));
    stop = high_resolution_clock::now();
    printf("Time: %ldms\n", duration_cast<microseconds>(stop - start).count());

    return 0;
}
