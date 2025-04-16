#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

#define MAX_VERTICES 100

// Structure for an adjacency list node
struct AdjListNode {

    int dest;

    struct AdjListNode* next;

};

// Structure for an adjacency list
struct AdjList {

    struct AdjListNode* head;

};



// Structure for a graph

struct Graph {

    int V;

    struct AdjList* array;

};



// Function to create a new adjacency list node

struct AdjListNode* newAdjListNode(int dest) {

    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));

    newNode->dest = dest;

    newNode->next = NULL;

    return newNode;

}



// Function to create a graph with V vertices

struct Graph* createGraph(int V) {

    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    graph->V = V;

    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; ++i)

        graph->array[i].head = NULL;

    return graph;

}



// Function to add an edge to an undirected graph

void addEdge(struct Graph* graph, int src, int dest) {

    struct AdjListNode* newNode = newAdjListNode(dest);

    newNode->next = graph->array[src].head;

    graph->array[src].head = newNode;

    newNode = newAdjListNode(src);

    newNode->next = graph->array[dest].head;

    graph->array[dest].head = newNode;

}



// Function to perform DFS recursively

void DFSUtil(struct Graph* graph, int v, bool visited[]) {

    visited[v] = true;

    printf("%d ", v);



    struct AdjListNode* temp = graph->array[v].head;

    while (temp) {

        if (!visited[temp->dest])

            DFSUtil(graph, temp->dest, visited);

        temp = temp->next;

    }

}



// Function to perform Depth First Search traversal

void DFS(struct Graph* graph, int startVertex) {

    bool* visited = (bool*)malloc(graph->V * sizeof(bool));

    for (int i = 0; i < graph->V; i++)

        visited[i] = false;

    DFSUtil(graph, startVertex, visited);

    free(visited);

}



int main() {

    int V = 5;

    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);

    addEdge(graph, 0, 2);

    addEdge(graph, 1, 2);

    addEdge(graph, 1, 3);

    addEdge(graph, 2, 3);

    addEdge(graph, 3, 4);



    printf("DFS traversal starting from vertex 0: ");

    DFS(graph, 0);

    printf("\n");



    return 0;

}