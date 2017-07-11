//
// Funções responsáveis pela leitura do arquivo de entrada.
//

#include "graph.h"

#ifndef GRAFOS2017_1_PERSISTENCE_H
#define GRAFOS2017_1_PERSISTENCE_H

/// Lê o arquivo de entrada e retorna um array de dois elementos contendo o número de vértices e de arestas do grafo.
/// \param fileName Nome do arquivo de entrada contendo o grafo.
/// \param graphSize Array com o número de vértices do grafo na primeira posição e número de arestas na segunda posição.
void getGraphSize(char *fileName, int *graphSize);

/// Lê o arquivo de entrada e adiciona os vértices no grafo passado.
/// \param fileName Nome do arquivo de entrada contendo o grafo.
/// \param numEdges Número de arestas do grafo.
/// \param graph Grafo onde adicionar as arestas.
void readInputFile(char *fileName, int numEdges, struct Graph *graph);

#endif //GRAFOS2017_1_PERSISTENCE_H
