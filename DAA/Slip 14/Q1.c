#include <stdio.h>

#include <stdlib.h>

#include <time.h>



// Function to perform Insertion Sort

void insertionSort(int arr[], int n) {

    int i, key, j;

    for (i = 1; i < n; i++) {

        key = arr[i];

        j = i - 1;



        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position

        while (j >= 0 && arr[j] > key) {

            arr[j + 1] = arr[j];

            j = j - 1;

        }

        arr[j + 1] = key;

    }

}



int main() {

    int n;

    printf("Enter the number of elements: ");

    scanf("%d", &n);



    int arr[n];

    printf("Enter the elements: ");

    for (int i = 0; i < n; i++)

        scanf("%d", &arr[i]);



    // Measure the time taken to perform insertion sort

    clock_t start_time = clock();

    insertionSort(arr, n);

    clock_t end_time = clock();



    printf("Sorted array: ");

    for (int i = 0; i < n; i++)

        printf("%d ", arr[i]);

    printf("\n");



    // Calculate the time taken in seconds

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Time taken to sort the elements: %f seconds\n", time_taken);



    return 0;

}