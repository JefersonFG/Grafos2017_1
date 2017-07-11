#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct node* createNode(int vertex) {
    struct node* newNode = malloc(sizeof(struct node));

    newNode->vertex = vertex;
    newNode->next = NULL;

    return newNode;
}


struct Graph* createGraph(int numVertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    int i;

    graph->numVertices = numVertices;
    graph->adjLists = malloc(numVertices * sizeof(struct node*));

    for (i = 0; i < numVertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(struct Graph *graph, int source, int destination) {
    // Adiciona aresta da origem para o destino
    struct node* newNode = createNode(destination);
    newNode->next = graph->adjLists[source];
    graph->adjLists[source] = newNode;

    // Adiciona aresta do destino para a origem
    newNode = createNode(source);
    newNode->next = graph->adjLists[destination];
    graph->adjLists[destination] = newNode;
}

void deleteGraph(struct Graph **graph) {
    int i;
    for (i = 0; i < (*graph)->numVertices; i++) {
        struct node* current = (*graph)->adjLists[i];
        struct node* next;

        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }
    }

    *graph = NULL;
}
