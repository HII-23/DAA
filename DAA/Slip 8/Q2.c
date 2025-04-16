#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices in the graph

// Function to find the nearest neighbor of a given vertex
int nearestNeighbor(int graph[V][V], int visited[], int src) {
    int minDist = INT_MAX;
    int nearestVertex = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && graph[src][i] && graph[src][i] < minDist) {
            minDist = graph[src][i];
            nearestVertex = i;
        }
    }

    return nearestVertex;
}

// Function to implement the nearest neighbor algorithm for TSP
void tspNearestNeighbor(int graph[V][V]) {
    int visited[V];
    int path[V + 1]; // Path array to store the final path
    int pathIndex = 0;

    // Initialize visited array
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    // Start from the first vertex (0)
    int currentVertex = 0;
    visited[currentVertex] = 1;

    // Add the first vertex to the path
    path[pathIndex++] = currentVertex;

    // Find the nearest neighbor for each vertex
    for (int count = 0; count < V - 1; count++) {
        int nearest = nearestNeighbor(graph, visited, currentVertex);
        visited[nearest] = 1;
        path[pathIndex++] = nearest;
        currentVertex = nearest;
    }

    // Add the starting vertex to complete the cycle
    path[pathIndex] = 0;

    // Print the tour
    printf("Tour: ");
    for (int i = 0; i < V + 1; i++)
        printf("%d ", path[i]);
    printf("\n");
}

int main() {
    // Example graph represented using adjacency matrix
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    tspNearestNeighbor(graph);

    return 0;
}