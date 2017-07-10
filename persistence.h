//
// Funções responsáveis pela leitura do arquivo de entrada.
//

#include <stdio.h>

#ifndef GRAFOS2017_1_PERSISTENCE_H
#define GRAFOS2017_1_PERSISTENCE_H

/// Lê o arquivo de entrada e retorna um array de dois elementos contendo o número de vértices e de arestas do grafo.
/// \param fileName Nome do arquivo de entrada contendo o grafo.
/// \return Array com o número de vértices do grafo na primeira posição e número de arestas na segunda posição.
int* getGraphSize(char* fileName);

/// Lê o arquivo de entrada retornando uma matriz que contém as arestas do grafo.
/// \param fileName Nome do arquivo de entrada contendo o grafo.
/// \param numEdges Número de arestas do grafo.
/// \return Matriz com as arestas do grafo lidas do arquivo de entrada.
int** readInputFile(char* fileName, int numEdges);

#endif //GRAFOS2017_1_PERSISTENCE_H
