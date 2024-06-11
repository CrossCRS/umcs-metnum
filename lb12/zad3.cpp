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

    uint count = 0;
    for (uint i = 1; i <= 20000 / (sizeof(uint) * 8); i++) {
        uint x = alcg_rand(i, a, c, M, seed);

        count += __builtin_popcount(x);
    }
    printf("Liczba jedynek: %u\n", count);
    return 0;
}
