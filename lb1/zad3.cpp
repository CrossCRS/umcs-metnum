#include <cstdio>

float sum_arr(float *arr, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n, m;
    printf("Podaj n m: ");
    scanf("%d %d", &n, &m);

    if (!(n > m)) {
        printf("n musi byc wieksze od m\n");
        return -1;
    }

    if (!((n & (n - 1)) == 0 && (m & (m - 1)) == 0)) {
        printf("n i m musza byc potegami dwojki\n");
        return -1;
    }

    float *arr = new float[n];

    for (int i = 0; i < n; i++) {
        arr[i] = 1.f / ((i % m + 1.f) * (i % m + 2.f));
    }

    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    printf("Suma = %f\n", sum_arr(arr, n));

    delete[] arr;
    return 0;
}
