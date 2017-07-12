#include <stdio.h>
#include <stdlib.h>
#include "graph_processing.h"
#include "queue.h"

int numOfConnectedComponentsBfs(struct Graph *graph, int numVertices, int numEdges) {
    int isNodeExplored[numVertices];
    struct Queue * queue = initializeQueue();
    struct node * current;
    int i, v, w, connections = 0;

    // initializes all nodes as unexplored
    for (i = 0; i < numVertices; i++){
        isNodeExplored[i] = 0;
    }

    for (i = 0; i < numVertices; i++){
        if (!isNodeExplored[i]){
            // BFS
            isNodeExplored[i] = 1;
            enqueue(queue, i);
            while (!isEmptyQueue(queue)){
                v = dequeue(queue);
                for (current = graph->adjLists[v]; current != NULL; current = current->next){
                    w = current->vertex;
                    if (!isNodeExplored[w]) {
                        isNodeExplored[w] = 1;
                        enqueue(queue, w);
                    }
                }
            }
            connections += 1;
        }
    }

    printf("Debug: numOfConnectedComponentsBfs\n");
    return connections;
}

int numOfConnectedComponentsDfs(struct Graph *graph, int numVertices, int numEdges) {
    printf("Debug: numOfConnectedComponentsDfs\n");
    return 0;
}

int* distancesBfs(struct Graph *graph, int numVertices, int numEdges) {
    int * distances = (int *) malloc(sizeof(int) * numVertices);
    struct Queue * queue = initializeQueue();
    struct node * current;
    int i, v, w;

    for (i = 0; i < numVertices; i++){
        distances[i] = -1;
    }
    distances[0] = 0; // Todas distâncias serão calculadas a partir do nodo 0
    enqueue(queue, 0);

    while (!isEmptyQueue(queue)){
        v = dequeue(queue);
        for (current = graph->adjLists[v]; current != NULL; current = current->next){
            w = current->vertex;
            if (distances[w] == -1) {
                distances[w] = distances[v] + 1;
                enqueue(queue, w);
            }
        }
    }

    printf("Debug: distancesBfs\n");
    return distances;
}

int* distancesDfs(struct Graph *graph, int numVertices, int numEdges) {
    printf("Debug: distancesDfs\n");
    return NULL;
}
