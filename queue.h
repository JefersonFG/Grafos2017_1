//
// Estrutura de fila utilizada para processamento BFS.
//

#ifndef GRAFOS2017_1_QUEUE
#define GRAFOS2017_1_QUEUE

/// Estrutura dos nodos da fila
struct queueNode {
	int data;
	struct queueNode* next;
};

/// Estrutura da fila
struct Queue {
    struct queueNode* front;
    struct queueNode* rear;
};

/// Inicializa uma fila.
/// \return Ponteiro para a memória da fila.
struct Queue * initializeQueue();

/// Retorna 1/0 se a fila estiver vazia
/// \param q Ponteiro da fila
/// \return 1 para fila vazia, 0 no caso contrário
int isEmptyQueue(struct Queue * q);

/// Adiciona um valor ao final da fila
/// \param q Ponteiro da fila
/// \param x Valor a ser adicionado
void enqueue(struct Queue * q, int x);

/// Remove o valor da frente da fila
/// \param q Ponteiro da fila
/// \return valor removido da fila
int dequeue(struct Queue * q);

#endif //GRAFOS2017_1_QUEUE
