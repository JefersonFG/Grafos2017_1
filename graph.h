//
// Estrutura do grafo a ser processado.
//

#ifndef GRAFOS2017_1_GRAPH_H
#define GRAFOS2017_1_GRAPH_H

/// Estrutura dos nodos do grafo.
struct node {
    int vertex;
    struct node *next;
};

/// Estrutura do grafo.
struct Graph
{
    int numVertices;
    struct node **adjLists;
};

/// Cria um novo nodo para adicionar no grafo.
/// \param vertex Vértice que o nodo representa.
/// \return Ponteiro para a memória do nodo.
struct node* createNode(int vertex);

/// Cria o grafo indicando quantos vértices ele terá.
/// \param numVertices Número de vértices do grafo.
/// \return Ponteiro para a memória do grafo.
struct Graph* createGraph(int numVertices);

/// Adiciona uma aresta no grafo.
/// \param graph Grafo no qual deve adicionar a aresta.
/// \param source Vértice de origem da aresta.
/// \param destination Vértice de destino da aresta.
void addEdge(struct Graph *graph, int source, int destination);

/// Remove o grafo da memória.
/// \param graph Grafo que deve ser removido da memória.
void deleteGraph(struct Graph *graph);

#endif //GRAFOS2017_1_GRAPH_H
