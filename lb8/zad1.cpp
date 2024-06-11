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

double maclaurin_exp(double x, double e) {
    double result = 0;
    double term = 0;
    int i = 0;

    do {
        term = pow(x, i) / factorial(i);
        result += term;
        i++;
    } while (term > e);

    return result;
}

int main() {
    auto start = high_resolution_clock::now();
    printf("e^1 (maclaurin) = %.16f\n", maclaurin_exp(1, pow(10, -16)));
    auto stop = high_resolution_clock::now();
    printf("Time: %ldms\n\n", duration_cast<microseconds>(stop - start).count());

    start = high_resolution_clock::now();
    printf("e^1 (stdlib) = %.16f\n", exp(1));
    stop = high_resolution_clock::now();
    printf("Time: %ldms\n", duration_cast<microseconds>(stop - start).count());

    return 0;
}
