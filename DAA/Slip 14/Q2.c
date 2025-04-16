#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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

// Structure for a queue node used in BFS
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Structure for a queue used in BFS
struct Queue {
    struct QueueNode *front, *rear;
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

// Function to create a new queue node
struct QueueNode* newQueueNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* q, int data) {
    struct QueueNode* newNode = newQueueNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* q) {
    if (q->front == NULL)
        return -1;
    struct QueueNode* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

// Function to perform Depth First Search traversal
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

// Function to perform Breadth First Search traversal
void BFS(struct Graph* graph, int startVertex) {
    bool* visited = (bool*)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; i++)
        visited[i] = false;

    struct Queue* queue = createQueue();
    visited[startVertex] = true;
    enqueue(queue, startVertex);

    while (queue->front != NULL) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        struct AdjListNode* temp = graph->array[currentVertex].head;
        while (temp) {
            int adjVertex = temp->dest;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }
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
    clock_t start_time_dfs = clock();
    DFS(graph, 0);
    clock_t end_time_dfs = clock();
    printf("\n");

    printf("BFS traversal starting from vertex 0: ");
    clock_t start_time_bfs = clock();
    BFS(graph, 0);
    clock_t end_time_bfs = clock();
    printf("\n");

    // Calculate the time taken for DFS and BFS in seconds
    double time_taken_dfs = ((double)(end_time_dfs - start_time_dfs)) / CLOCKS_PER_SEC;
    double time_taken_bfs = ((double)(end_time_bfs - start_time_bfs)) / CLOCKS_PER_SEC;

    printf("Time taken for DFS: %f seconds\n", time_taken_dfs);
    printf("Time taken for BFS: %f seconds\n", time_taken_bfs);

    return 0;
}