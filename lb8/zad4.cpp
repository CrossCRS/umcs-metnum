#include <cstdio>
#include <cmath>
#include <vector>

typedef std::vector<std::vector<double>> matrix_t;

struct Point {
    double x;
    double y;
};

void approx(const std::vector<Point> points, double &a, double &b, double &c) {
    matrix_t A(3, std::vector<double>(3));

    int i = 0;
    for (auto const &point : points) {
        A[0][0] += pow(point.x, 4);
        A[0][1] += pow(point.x, 3);
        A[0][2] += pow(point.x, 2);

        A[1][0] += pow(point.x, 3);
        A[1][1] += pow(point.x, 2);
        A[1][2] += point.x;

        A[2][0] += pow(point.x, 2);
        A[2][1] += pow(point.x, 1);
        A[2][2] += i;

        i++;
    }
}

int main() {
    std::vector<Point> points = {
        { 0.00, 2.00 },
        { 0.50, 2.48 },
        { 1.00, 2.84 },
        { 1.50, 3.00 },
        { 2.00, 2.91 }
    };

    double a, b, c;
    approx(points, a, b, c);

    printf("a = %f\nb = %f\n\nc = %f", a, b, c);
    printf("f(2) = ax + b = %f\n", a * 2 + b);

    return 0;
}
