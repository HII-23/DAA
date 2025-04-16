#include <stdio.h>

#define MAX_SIZE 100

// Function to find all subsets with a given sum
void findSubsets(int arr[], int n, int sum, int subset[], int subsetSize, int total, int k) {
    if (total == sum) {
        // Print the subset
        printf("Subset found: ");
        for (int i = 0; i < subsetSize; i++)
            printf("%d ", subset[i]);
        printf("\n");
        return;
    }

    // If we reached the end of the array or sum exceeded, return
    if (k >= n || total > sum)
        return;

    // Include the current element in the subset
    subset[subsetSize] = arr[k];

    // Recursively find subsets including and excluding the current element
    findSubsets(arr, n, sum, subset, subsetSize + 1, total + arr[k], k + 1);
    findSubsets(arr, n, sum, subset, subsetSize, total, k + 1);
}

int main() {
    int arr[MAX_SIZE], n, sum;

    // Input number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input the elements
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Input the sum
    printf("Enter the sum: ");
    scanf("%d", &sum);

    int subset[MAX_SIZE];
    findSubsets(arr, n, sum, subset, 0, 0, 0);

    return 0;
}