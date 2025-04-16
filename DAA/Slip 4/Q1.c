#include <stdio.h>

#include <stdlib.h>

#include <time.h>

// Merge two subarrays of arr[].

// First subarray is arr[l..m].

// Second subarray is arr[m+1..r].

void merge(int arr[], int l, int m, int r)
{

    int i, j, k;

    int n1 = m - l + 1;

    int n2 = r - m;

    // Create temporary arrays

    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]

    for (i = 0; i < n1; i++)

        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)

        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]

    i = 0; // Initial index of first subarray

    j = 0; // Initial index of second subarray

    k = l; // Initial index of merged subarray

    while (i < n1 && j < n2)
    {

        if (L[i] <= R[j])
        {

            arr[k] = L[i];

            i++;
        }
        else
        {

            arr[k] = R[j];

            j++;
        }

        k++;
    }

    // Copy the remaining elements of L[], if any

    while (i < n1)
    {

        arr[k] = L[i];

        i++;

        k++;
    }

    // Copy the remaining elements of R[], if any

    while (j < n2)
    {

        arr[k] = R[j];

        j++;

        k++;
    }
}

// l is for left index and r is right index of the sub-array of arr to be sorted

void mergeSort(int arr[], int l, int r)
{

    if (l < r)
    {

        // Same as (l+r)/2, but avoids overflow for large l and h

        int m = l + (r - l) / 2;

        // Sort first and second halves

        mergeSort(arr, l, m);

        mergeSort(arr, m + 1, r);

        // Merge the sorted halves

        merge(arr, l, m, r);
    }
}

int main()
{

    int n;

    clock_t start, end;

    double cpu_time_used;

    printf("Enter the number of elements: ");

    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers:\n", n);

    for (int i = 0; i < n; i++)
    {

        scanf("%d", &arr[i]);
    }

    start = clock();

    mergeSort(arr, 0, n - 1);

    end = clock();

    printf("Sorted array:\n");

    for (int i = 0; i < n; i++)
    {

        printf("%d ", arr[i]);
    }

    printf("\n");

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort: %lf seconds\n", cpu_time_used);

    return 0;
}