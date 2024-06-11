#include <iostream>
#include <format>
#include <cmath>
#include <vector>

struct Point {
    double x, y;
};

double euclidean_dist(const Point &p1, const Point &p2) {
    return std::sqrt(
        std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

double manhattan_dist(Point &p1, Point &p2) {
    return std::fabs(p2.x - p1.x) + std::fabs(p2.y - p1.y);
}

double maximum_dist(Point &p1, Point &p2) {
    double a = std::fabs(p2.x - p1.x);
    double b = std::fabs(p2.y - p1.y);

    if (a > b) {
        return a;
    } else {
        return b;
    }
}

double river_dist(const Point &p1, const Point &p2) {
    if (p1.x == p2.x) {
        return euclidean_dist(p1, p2);
    } else {
        return euclidean_dist(p1, {p1.x, 0})
             + euclidean_dist({p1.x, 0}, {p2.x, 0})
             + euclidean_dist({p2.x, 0}, p2);
    }
}

double rail_dist(const Point &p1, const Point &p2) {
    // Czy sa wspolliniowe?
    if (std::fabs((p1.x * p2.y) - (p1.y * p2.x)) < std::pow(10, -5)) {
        return euclidean_dist(p1, p2);
    } else {
        return euclidean_dist(p1, {0, 0})
             + euclidean_dist({0, 0}, p2);
    }
}

int main() {
    Point p1 = {1, 1};
    Point p2 = {3, 2};

    std::cout << std::format("Euclidean dist: {}\n", euclidean_dist(p1, p2));
    std::cout << std::format("Manhattan dist: {}\n", manhattan_dist(p1, p2));
    std::cout << std::format("Maximum dist: {}\n", maximum_dist(p1, p2));

    std::cout << std::format("River dist: {}\n", river_dist(p1, p2));
    std::cout << std::format("Rail dist: {}\n", rail_dist(p1, p2));
    return 0;
}
