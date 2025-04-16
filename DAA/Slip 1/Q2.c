#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick Sort recursive function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    FILE *file;

    // Generate random numbers and write to file
    file = fopen("numbers.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    srand(time(NULL));
    int n_values[] = {10, 100, 1000, 10000};

    for (int k = 0; k < sizeof(n_values) / sizeof(n_values[0]); k++) {
        int n = n_values[k];
        fprintf(file, "n = %d\n", n);
        for (int i = 0; i < n; i++) {
            fprintf(file, "%d ", rand() % 1000);
        }
        fprintf(file, "\n");
    }
    fclose(file);

    // Read numbers from file and sort
    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    int n;
    clock_t start, end;
    double cpu_time_used;

    while (fscanf(file, "n = %d", &n) == 1) {
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        for (int i = 0; i < n; i++) {
            fscanf(file, "%d", &arr[i]);
        }

        start = clock();
        quickSort(arr, 0, n - 1);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken to sort %d elements using Quick sort: %lf seconds\n", n, cpu_time_used);

        // Print sorted array if n == 10
        if (n == 10) {
            printf("Sorted elements:\n");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }

        free(arr);
    }

    fclose(file);
    return 0;
}
