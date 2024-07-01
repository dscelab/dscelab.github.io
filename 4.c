#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 30000
#define NTIMES 5000

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    return i + 1;
}

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quicksort(a, low, pi - 1);
        quicksort(a, pi + 1, high);
    }
}

int main() {
    int a[MAXSIZE], n, k, i;
    double runtime = 0;
    clock_t start, end;

    printf("Enter the value of n\n");
    scanf("%d", &n);

    for (k = 1; k <= NTIMES; k++) {
        srand(time(0));
        for (i = 0; i < n; i++) {
            a[i] = rand();
        }

        start = clock();
        quicksort(a, 0, n - 1);
        end = clock();

        runtime += ((double)(end - start)) / CLOCKS_PER_SEC;
    }

    runtime /= NTIMES;

    printf("\nSorted elements are\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }

    printf("Time taken for sorting is %lf seconds\n", runtime);

    return 0;
}