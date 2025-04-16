#include <stdio.h>

#include <stdlib.h>



// Structure to represent an item

struct Item {

    int value;

    int weight;

    double ratio; // Value-to-weight ratio

};



// Comparator function for sorting items based on value-to-weight ratio in non-increasing order

int compare(const void *a, const void *b) {

    double ratioA = ((struct Item *)a)->ratio;

    double ratioB = ((struct Item *)b)->ratio;

    return (ratioB > ratioA) ? 1 : -1;

}



// Function to solve fractional knapsack problem using greedy method

void fractionalKnapsack(struct Item items[], int n, int capacity) {

    // Sort items based on value-to-weight ratio in non-increasing order

    qsort(items, n, sizeof(items[0]), compare);



    int currentWeight = 0; // Current weight in knapsack

    double finalValue = 0.0; // Final value of items taken



    printf("Items selected:\n");



    // Loop through sorted items and add them to knapsack greedily

    for (int i = 0; i < n; i++) {

        // If adding the entire item doesn't exceed the capacity, add it fully

        if (currentWeight + items[i].weight <= capacity) {

            currentWeight += items[i].weight;

            finalValue += items[i].value;

            printf("Item with value %d and weight %d\n", items[i].value, items[i].weight);

        } else {

            // Otherwise, take a fraction of the item to fill the knapsack

            int remainingWeight = capacity - currentWeight;

            finalValue += items[i].value * ((double)remainingWeight / items[i].weight);

            printf("Item with value %d and weight %d (fraction %.2lf)\n", items[i].value, items[i].weight, ((double)remainingWeight / items[i].weight));

            break; // Knapsack is full

        }

    }



    printf("Total value obtained: %.2lf\n", finalValue);

}



int main() {

    int n, capacity;



    printf("Enter the number of items: ");

    scanf("%d", &n);



    struct Item items[n];



    printf("Enter the profit and weight of each item:\n");

    for (int i = 0; i < n; i++) {

        printf("Item %d: ", i + 1);

        scanf("%d %d", &items[i].value, &items[i].weight);

        items[i].ratio = (double)items[i].value / items[i].weight;

    }



    printf("Enter the capacity of the knapsack: ");

    scanf("%d", &capacity);



    fractionalKnapsack(items, n, capacity);



    return 0;

}