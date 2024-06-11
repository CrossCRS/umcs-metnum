#include <cstdio>
#include <cmath>

uint alcg_rand(int n, int a, int c, u_int64_t M, int seed) {
    if (n == 0) return seed;

    return (a * alcg_rand(n - 1, a, c, M, seed) + c) % M;
}

int main() {
    int a = 134775813;
    int c = 1;
    u_int64_t M = std::pow(2, 32);
    int seed = 42;

    for (uint i = 1; i <= 101; i += 2) {
        uint x = alcg_rand(i, a, c, M, seed);
        uint y = alcg_rand(i + 1, a, c, M, seed);
        printf("%u %u ", x, y);
        // printf("<circle r=\"1\" cx=\"%d\" cy=\"%d\" fill=\"red\" />", x, y);
    }
    return 0;
}
