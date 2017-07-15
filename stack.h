//
// Estrutura de pilha utilizada para processamento DFS.
//

#ifndef GRAFOS2017_1_STACK
#define GRAFOS2017_1_STACK

struct Stack {
	int data;
	struct Stack * next;
};

// Inicializa uma pilha
// \ return  local para a pilha
struct Stack * initializeStack();

// Testa se uma pilha está vazia
// \ param s -> Qual pilha deve ser verificada
// \ return 1 se a pilha estiver vazia, 0 caso contrário
int isEmptyStack(struct Stack * s);

// Adiciona um valor na pilha
// \ param s -> Em qual pilha deve ser adicionada
// \ param x -> Valor que deve ser adicionado ao topo da pilha
struct Stack * pushStack(struct Stack * s, int x);

// Retira um valor da pilha
// \ param s -> De qual pilha deve retirar o valor
// \ param x -> Onde retorna o valor retirado da pilha
int popStack (struct Stack **s, int *x);


#endif //GRAFOS2017_1_STACK