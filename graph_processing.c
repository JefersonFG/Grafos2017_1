#include <stdio.h>
#include <stdlib.h>
#include "graph_processing.h"
#include "queue.h"
#include "stack.h"

void DFS(int node, int isNodeExplored[], int numVertices) {
    // node -> de qual nodo irá partir o DFS
    isNodeExplored[node] = 1;
    for (i = 0; i < numVertices; i++){
        if(!isNodeExplored[i]){
            DFS(i, isNodeExplored, numVertices);
        }
    }
}

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

    return connections;
}

int numOfConnectedComponentsDfs(struct Graph *graph, int numVertices, int numEdges) {
    int isNodeExplored[numVertices];
    struct Stack * stack = initializeStack();
    struct node * current;
    int i, v, w, connections = 0;

    // initializes all nodes as unexplored
    for (i = 0; i < numVertices; i++){
        isNodeExplored[i] = 0;
    }

    for (i = 0; i < numVertices; i++){
        if (!isNodeExplored[i]){
            // DFS
            isNodeExplored[i] = 1;
            stack = pushStack(stack, i);
            while (!isEmptyStack(stack)){
                popStack(&stack, &v);
                for (current = graph->adjLists[v]; current != NULL; current = current->next){
                    w = current->vertex;
                    if (!isNodeExplored[w]) {
                        isNodeExplored[w] = 1;
                        stack = pushStack(stack, w);
                    }
                }
            }
            connections += 1;
        }
    }
    
            
    return connections;
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

    return distances;
}

int* distancesDfs(struct Graph *graph, int numVertices, int numEdges) {
       int * distances = (int *) malloc(sizeof(int) * numVertices);
    struct Stack * stack = initializeStack();
    struct node * current;
    int i, v, w;

    for (i = 0; i < numVertices; i++){
        distances[i] = -1;
    }
    distances[0] = 0; // Todas distâncias serão calculadas a partir do nodo 0
    stack = pushStack(stack, 0);
    
    while (!isEmptyStack(stack)){
        popStack(&stack, &v);
        for (current = graph->adjLists[v]; current != NULL; current = current->next){
            w = current->vertex;
            if (distances[w] == -1) {
                distances[w] = distances[v] + 1;
                stack = pushStack(stack, w);
            }
        }
    }

    return distances;
}
