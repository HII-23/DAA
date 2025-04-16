#include <stdio.h>

#include <stdlib.h>



// Structure to represent a node in the priority queue

struct Node {

    int level;

    int profit;

    int weight;

    float bound;

};



// Function to swap two nodes

void swap(struct Node* a, struct Node* b) {

    struct Node t = *a;

    *a = *b;

    *b = t;

}



// Function to perform min-heapify operation

void minHeapify(struct Node* heap, int i, int size) {

    int smallest = i;

    int left = 2 * i + 1;

    int right = 2 * i + 2;



    if (left < size && heap[left].bound < heap[smallest].bound)

        smallest = left;



    if (right < size && heap[right].bound < heap[smallest].bound)

        smallest = right;



    if (smallest != i) {

        swap(&heap[i], &heap[smallest]);

        minHeapify(heap, smallest, size);

    }

}



// Function to build a min-heap

void buildMinHeap(struct Node* heap, int size) {

    for (int i = size / 2 - 1; i >= 0; i--)

        minHeapify(heap, i, size);

}



// Function to extract the minimum node from the priority queue

struct Node extractMin(struct Node* heap, int* size) {

    struct Node minNode = heap[0];

    heap[0] = heap[*size - 1];

    (*size)--;

    minHeapify(heap, 0, *size);

    return minNode;

}



// Function to calculate the bound of a node

float calculateBound(struct Node u, int n, int W, int* wt, int* val) {

    if (u.weight >= W)

        return 0;



    float bound = u.profit;

    int j = u.level + 1;

    int totalWeight = u.weight;



    while (j < n && totalWeight + wt[j] <= W) {

        bound += val[j];

        totalWeight += wt[j];

        j++;

    }



    if (j < n)

        bound += (W - totalWeight) * ((float)val[j] / wt[j]);



    return bound;

}



// Function to solve the 0/1 Knapsack Problem using LCBB

int knapsack(int W, int wt[], int val[], int n) {

    struct Node* heap = (struct Node*)malloc(sizeof(struct Node) * (n + 1));

    int heapSize = 0;



    struct Node u, v;

    u.level = -1;

    u.profit = u.weight = 0;

    u.bound = calculateBound(u, n, W, wt, val);



    heap[heapSize++] = u;



    int maxProfit = 0;



    while (heapSize > 0) {

        u = extractMin(heap, &heapSize);



        if (u.bound > maxProfit) {

            v.level = u.level + 1;

            v.weight = u.weight + wt[v.level];

            v.profit = u.profit + val[v.level];



            if (v.weight <= W && v.profit > maxProfit)

                maxProfit = v.profit;



            v.bound = calculateBound(v, n, W, wt, val);



            if (v.bound > maxProfit)

                heap[heapSize++] = v;



            v.weight = u.weight;

            v.profit = u.profit;

            v.bound = calculateBound(v, n, W, wt, val);



            if (v.bound > maxProfit)

                heap[heapSize++] = v;

        }

    }



    free(heap);

    return maxProfit;

}



int main() {

    int val[] = {60, 100, 120};

    int wt[] = {10, 20, 30};

    int W = 50;

    int n = sizeof(val) / sizeof(val[0]);



    printf("Maximum value that can be obtained is %d\n", knapsack(W, wt, val, n));



    return 0;

}