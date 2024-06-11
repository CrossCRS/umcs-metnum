#include <cstdio>
#include <cmath>
#include <vector>

struct Point {
    double x;
    double y;
};

void approx(const std::vector<Point> points, double &a, double &b) {
    double A = 0.0, B = 0.0, C = 0.0, D = 0.0;

    for (auto const &point : points) {
        A += point.x * point.y;
        B += point.x;
        C += point.y;
        D += pow(point.x, 2);
    }

    size_t n = points.size();
    a = (n * A - B * C) / (n * D - pow(B, 2));
    b = (C * D - A * B) / (n * D - pow(B, 2));
}

int main() {
    std::vector<Point> points = {
        { 1.1, 2.1 },
        { 1.4, 2.3 },
        { 1.8, 2.9 },
        { 2.5, 3.2 },
        { 2.8, 3.6 },
        { 3.0, 4.2 }
    };

    double a, b;
    approx(points, a, b);

    printf("a = %f\nb = %f\n", a, b);
    printf("f(2) = ax + b = %f\n", a * 2 + b);

    return 0;
}
