//
// Funções responsáveis pelo processamento do grafo.
//

#ifndef GRAFOS2017_1_GRAPH_PROCESSING_H
#define GRAFOS2017_1_GRAPH_PROCESSING_H

/// Retorna o número de componentes conexos utilizando o algoritmo bfs.
/// \param graph Matriz de adjacência representando as arestas do grafo.
/// \param numVertices Número de vértices do grafo.
/// \param numEdges Número de arestas do grafo.
/// \return Número de componentes conexos do grafo.
int numOfConnectedComponentsBfs(int **graph, int numVertices, int numEdges);

/// Retorna o número de componentes conexos utilizando o algoritmo dfs.
/// \param graph Matriz de adjacência representando as arestas do grafo.
/// \param numVertices Número de vértices do grafo.
/// \param numEdges Número de arestas do grafo.
/// \return Número de componentes conexos do grafo.
int numOfConnectedComponentsDfs(int **graph, int numVertices, int numEdges);

/// Retorna uma lista com as distâncias dos vértices à partir do vértice 0 utilizando o algoritmo bfs.
/// \param graph Matriz de adjacência representando as arestas do grafo.
/// \param numVertices Número de vértices do grafo.
/// \param numEdges Número de arestas do grafo.
/// \return Lista de distâncias do vértice n para o vértice 0.
int* distancesBfs(int **graph, int numVertices, int numEdges);

/// Retorna uma lista com as distâncias dos vértices à partir do vértice 0 utilizando o algoritmo dfs.
/// \param graph Matriz de adjacência representando as arestas do grafo.
/// \param numVertices Número de vértices do grafo.
/// \param numEdges Número de arestas do grafo.
/// \return Lista de distâncias do vértice n para o vértice 0.
int* distancesDfs(int **graph, int numVertices, int numEdges);

#endif //GRAFOS2017_1_GRAPH_PROCESSING_H
