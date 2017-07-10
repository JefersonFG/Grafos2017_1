#include <stdio.h>
#include <string.h>
#include "persistence.h"
#include "graph_processing.h"

/// Função principal do programa, processa os argumentos e exibe o resultado na tela.
/// \param argc Número de argumentos passados, que deve ser 4 (main, algoritmo, função e arquivo)
/// \param argv Argumentos passados para o programa.
/// \return Em geral, 0 para indicar que o programa finalizou corretamente.
int main(int argc, char *argv[]) {
    int vertices;
    int edges;
    int graphSize[2];
    int* graphEdges;

    if (argc != 4) {
        printf("Wrong input, supported format: ./main -algorithm -function filename");
        return 0;
    }

    getGraphSize(argv[3]);
    readInputFile(argv[3], 0);

    if (!strcmp(argv[1], "-bfs")) {
        if (!strcmp(argv[2], "-c")) {
            numOfConnectedComponentsBfs(0, 0, 0);
        } else {
            distancesBfs(0, 0, 0);
        }
    } else {
        if (!strcmp(argv[2], "-c")) {
            numOfConnectedComponentsDfs(0, 0, 0);
        } else {
            distancesDfs(0, 0, 0);
        }
    }

    return 0;
}