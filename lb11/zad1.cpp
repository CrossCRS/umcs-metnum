#include <complex>
#include <iostream>
#include <vector>

std::complex<double> zad1(std::vector<double> &poly, std::complex<double> &z) {
    std::complex<double> result = 0;

    for (int i = (int)poly.size(); i >= 0; i--) {
        result = result * z + poly[i];
    }

    return result;
}

std::pair<std::complex<double>, std::complex<double>> zad2(std::vector<double> &poly, std::complex<double> &z) {
    std::complex<double> r1 = 0;
    std::complex<double> r2 = 0;

    for (int i = (int)poly.size(); i > 0; i--) {
        r1 = r1 * z + i * poly[i];

        if (i > 1)
            r2 = r2 * z + i * (i - 1) * poly[i];
    }

    return std::pair(r1, r2);
}

// popsute?
void zad3(std::vector<double> &poly, std::complex<double> z) {
    for (int i = 0; i < 10; i++) {
        auto w = zad1(poly, z);
        auto p = zad2(poly, z);
        double n = (double)poly.size();

        auto g = p.first / w;
        auto h = g * g - p.second / w;

        auto sq = std::sqrt((n - 1) * (n * h - g * g));

        std::complex<double> a;

        if (std::abs(g + sq) > std::abs(g - sq)) {
            a = g + sq;
        } else {
            a = g - sq;
        }

        a = n / a;

        z = z - a;

        std::cout << z << "\n";
    }
}

int main() {
    std::vector<double> poly = { -6, 11, -6, 1 };
    std::complex<double> z = std::complex<double>(10, 0);

    zad3(poly, z);

    // std::cout << "Wartosc wielomianu w punkcie " << z << " wynosi: " << zad1(poly, z) << "\n";

    // auto r = zad2(poly, z);
    // std::cout << "Wartosc pochodnych w punkcie " << z << "\n";
    // std::cout << "\t" << r.first << "\n";
    // std::cout << "\t" << r.second << "\n";

    // std::cout << "\n";

    // poly = { -1, 11, -6, 1 };

    // std::cout << "Wartosc wielomianu w punkcie " << z << " wynosi: " << zad1(poly, z) << "\n";

    // r = zad2(poly, z);
    // std::cout << "Wartosc pochodnych w punkcie " << z << "\n";
    // std::cout << "\t" << r.first << "\n";
    // std::cout << "\t" << r.second << "\n";

    return 0;
}
