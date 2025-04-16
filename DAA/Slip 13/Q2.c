#include <stdio.h>
#include <limits.h>

// Function to find the minimum value
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find the cost of the optimal binary search tree
int optimalSearchTree(int keys[], int freq[], int n) {
    int cost[n][n];

    // For single key, cost is equal to its frequency
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    // L is the chain length
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            // Try making all keys in the range keys[i..j] as root
            for (int r = i; r <= j; r++) {
                // Calculate cost when keys[r] becomes root of this subtree
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        freq[r];
                cost[i][j] = min(cost[i][j], c);
            }
        }
    }
    return cost[0][n - 1];
}

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    printf("Cost of optimal BST is %d\n", optimalSearchTree(keys, freq, n));

    return 0;
}