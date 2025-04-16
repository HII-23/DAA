#include <stdio.h>
#include <limits.h>

#define MAX_KEYS 10

// Function to find the minimum of two values
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to construct optimal binary search tree
void constructOBST(int keys[], int freq[], int n) {
    int cost[n][n];

    // cost[i][j] will store the cost of the optimal binary search tree with keys[i] to keys[j]

    // Initialize cost[i][i] to the frequency of the single key at i
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    // For chains of length 2 to n
    for (int chainLen = 2; chainLen <= n; chainLen++) {
        // For each chain starting at i
        for (int i = 0; i <= n - chainLen; i++) {
            // Get the end of the chain
            int j = i + chainLen - 1;

            cost[i][j] = INT_MAX;

            // Try making each key in the chain the root
            for (int k = i; k <= j; k++) {
                // Cost when keys[k] is root
                int rootCost = ((k > i) ? cost[i][k - 1] : 0) +
                               ((k < j) ? cost[k + 1][j] : 0) +
                               freq[k];

                cost[i][j] = min(cost[i][j], rootCost);
            }
        }
    }

    printf("Cost of optimal binary search tree is: %d\n", cost[0][n - 1]);

    // Best-case complexity information
    printf("Best-case Time Complexity of OBST: O(n^3)\n");
}

int main() {
    int keys[MAX_KEYS] = {10, 20, 30, 40, 50};
    int freq[MAX_KEYS] = {4, 2, 6, 3, 1};
    int n = sizeof(keys) / sizeof(keys[0]);

    constructOBST(keys, freq, n);

    return 0;
}
