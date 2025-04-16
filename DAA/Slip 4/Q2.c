#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
};

// Function to compare items based on value-to-weight ratio
int compare(const void *a, const void *b) {
    double ratioA = ((struct Item *)a)->value / (double)((struct Item *)a)->weight;
    double ratioB = ((struct Item *)b)->value / (double)((struct Item *)b)->weight;
    return (ratioB > ratioA) ? 1 : -1;
}

// Function to solve knapsack problem using Greedy method
void knapsackGreedy(int W, struct Item items[], int n) {
    // Sort items based on value-to-weight ratio
    qsort(items, n, sizeof(struct Item), compare);

    int totalWeight = 0;
    double totalValue = 0.0;

    printf("Selected items:\n");

    // Iterate through sorted items and add them to knapsack
    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= W) {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Item with value %d and weight %d\n", items[i].value, items[i].weight);
        } else {
            // Fractional knapsack is not allowed, so break if knapsack is full
            break;
        }
    }

    printf("Total value: %.2lf\n", totalValue);
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &W);

    struct Item items[n];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    knapsackGreedy(W, items, n);

    return 0;
}