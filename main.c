#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "persistence.h"
#include "graph_processing.h"

/// Função que valida o input recebido pelo programa.
/// \param argc Número de argumentos passados, que deve ser 4 (main, algoritmo, função e arquivo) ou 5 (registro de desempenho).
/// \param argv Argumentos passados para o programa.
/// \return Se o input for válido retorna 1, se não retorna 0.
int validateInput(int argc, char* argv[]);

/// Função que exibe na tela o número de componentes conexos do grafo.
/// \param components Número de componentes conexos do grafo.
void printComponents(int components);

/// Função que exibe na tela as distâncias dos vértices ao vértice 0.
/// \param distances Distâncias dos vértices ao vértice 0.
/// \param vertices Número de vértices.
void printDistances(int *distances, int vertices);

/// Função principal do programa, processa os argumentos e exibe o resultado na tela.
/// \param argc Número de argumentos passados, que deve ser 4 (main, algoritmo, função e arquivo) ou 5 (registro de desempenho).
/// \param argv Argumentos passados para o programa.
/// \return Em geral, 0 para indicar que o programa finalizou corretamente.
int main(int argc, char *argv[]) {
    int numVertices;
    int numEdges;
    int *graphSize = NULL;

    struct Graph* graph = NULL;

    int *distances = NULL;
    int numComponents;

    if (validateInput(argc, argv) == 0) {
        printf("Wrong input, supported format: ./main -algorithm -function filename\n");
        printf("Add a -debug at the end to receive information on performance metrics\n");
        exit(1);
    }

    graphSize = (int*) calloc(2, sizeof(int));

    getGraphSize(argv[3], graphSize);
    numVertices = graphSize[0];
    numEdges = graphSize[1];

    graph = createGraph(numVertices);

    readInputFile(argv[3], numEdges, graph);

    if (!strcmp(argv[1], "-bfs")) {
        if (!strcmp(argv[2], "-c")) {
            numComponents = numOfConnectedComponentsBfs(graph, numVertices, numEdges);
            printComponents(numComponents);
        } else {
            distances = distancesBfs(graph, numVertices, numEdges);
            printDistances(distances, numVertices);
        }
    } else {
        if (!strcmp(argv[2], "-c")) {
            numComponents = numOfConnectedComponentsDfs(graph, numVertices, numEdges);
            printComponents(numComponents);
        } else {
            distances = distancesDfs(graph, numVertices, numEdges);
            printDistances(distances, numVertices);
        }
    }

    if (graphSize != NULL)
        free(graphSize);

    if (graph != NULL)
        deleteGraph(graph);

    if (distances != NULL)
        free(distances);

    return 0;
}

int validateInput(int argc, char *argv[]) {
    if ((argc == 4 || (argc == 5 && !strcmp(argv[4],"-debug")))
        && (!strcmp(argv[1],"-bfs") || !strcmp(argv[1],"-dfs")) && (!strcmp(argv[2],"-c") || !strcmp(argv[2],"-d")))
        return 1;
    else
        return 0;
}

void printComponents(int components) {
    printf("%d", components);
}

void printDistances(int *distances, int numVertices) {
    if (distances != NULL) {
        int i;

        for (i = 0; i < (numVertices - 1); i++) {
            printf("%d ", distances[i]);
        }

        printf("%d", distances[i]);
    } else {
        printf("Error calculating distances");
        exit(1);
    }
}