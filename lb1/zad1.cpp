#include <cstdio>

int main() {
    float a = 0;
    for (int i = 0; i < 10; i++) {
        a += (i + 0.1);
    }
    printf("%f\n", a);

    float b = 0;
    for (int i = 9; i >= 0; i--) {
        b += (i + 0.1);
    }
    printf("%f\n", b);

    return 0;
}
