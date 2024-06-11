#include <cstdio>

// Algorytm Gilla-Mollera
float sum_arr(float *arr, int n) {
    float sum = 0;
    float sum_old = 0;
    float p = 0;

    for (int i = 0; i < n; i++) {
        sum = sum_old + arr[i];
        p = p + (arr[i] - (sum - sum_old));
        sum_old = sum;
    }

    return sum + p;
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
