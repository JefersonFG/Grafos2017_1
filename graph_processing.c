#include <stdio.h>
#include <stdlib.h>
#include "graph_processing.h"
#include "queue.h"

int numOfConnectedComponentsBfs(struct Graph *graph, int numVertices, int numEdges) {
    printf("Debug: numOfConnectedComponentsBfs\n");
    return 0;
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
