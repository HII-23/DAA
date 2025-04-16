#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices

// Function to count the number of live nodes, E nodes, and dead nodes
void classifyNodes(bool graph[V][V]) {
    int liveNodes = 0, eNodes = 0, deadNodes = 0;

    for (int i = 0; i < V; i++) {
        int degree = 0;
        for (int j = 0; j < V; j++) {
            if (graph[i][j])
                degree++;
        }

        if (degree == 0)
            deadNodes++;
        else if (degree == 1)
            eNodes++;
        else
            liveNodes++;
    }

    printf("Live Nodes: %d\n", liveNodes);
    printf("E Nodes: %d\n", eNodes);
    printf("Dead Nodes: %d\n", deadNodes);
}

int main() {
    bool graph[V][V] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 1, 0, 0, 0}
    };

    classifyNodes(graph);

    return 0;
}