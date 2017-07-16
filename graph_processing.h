//
// Funções responsáveis pelo processamento do grafo.
//

#include "graph.h"

#ifndef GRAFOS2017_1_GRAPH_PROCESSING_H
#define GRAFOS2017_1_GRAPH_PROCESSING_H

/// Função utilizada para marcar os vértices passados pelo DFS
/// \ param numVertices Número de vértices do grafo
/// \ param node Nodo a partir do qual será calculado o DFS
/// \ param isNodeExplored[] Vetor que marca os nodos já visitados
/// \ param numVertices Serve para controlar se todos os nodos foram explorados ou não
void DFS(int node, isNodeExplored[], int numVertices);

/// Retorna o número de componentes conexos utilizando o algoritmo bfs.
/// \param graph Grafo a ser processado.
/// \param numVertices Número de vértices do grafo.
/// \param numEdges Número de arestas do grafo.
/// \return Número de componentes conexos do grafo.
int numOfConnectedComponentsBfs(struct Graph *graph, int numVertices, int numEdges);

/// Retorna o número de componentes conexos utilizando o algoritmo dfs.
/// \param graph Grafo a ser processado.
/// \param numVertices Número de vértices do grafo.
/// \param numEdges Número de arestas do grafo.
/// \return Número de componentes conexos do grafo.
int numOfConnectedComponentsDfs(struct Graph *graph, int numVertices, int numEdges);

/// Retorna uma lista com as distâncias dos vértices à partir do vértice 0 utilizando o algoritmo bfs.
/// \param graph Grafo a ser processado.
/// \param numVertices Número de vértices do grafo.
/// \param numEdges Número de arestas do grafo.
/// \return Lista de distâncias do vértice n para o vértice 0.
int* distancesBfs(struct Graph *graph, int numVertices, int numEdges);

/// Retorna uma lista com as distâncias dos vértices à partir do vértice 0 utilizando o algoritmo dfs.
/// \param graph Grafo a ser processado.
/// \param numVertices Número de vértices do grafo.
/// \param numEdges Número de arestas do grafo.
/// \return Lista de distâncias do vértice n para o vértice 0.
int* distancesDfs(struct Graph *graph, int numVertices, int numEdges);

#endif //GRAFOS2017_1_GRAPH_PROCESSING_H
