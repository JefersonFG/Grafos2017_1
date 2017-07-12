#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct Queue * initializeQueue() {
    struct Queue * q = (struct Queue *) malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmptyQueue(struct Queue * q) {
    return  (q == NULL || q->front == NULL) ? 1 : 0 ;
}

void enqueue(struct Queue * q, int x) {
	struct queueNode* temp =
		(struct queueNode*)malloc(sizeof(struct queueNode));
	temp->data =x;
	temp->next = NULL;
	if(q->front == NULL && q->rear == NULL){
		q->front = temp;
        q->rear = temp;
	} else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(struct Queue * q) {
	struct queueNode* temp = q->front;
    int val = temp->data;
	if(q->front == NULL) {
        printf("\nError: Trying to dequeue empty Queue\n");
		return -1;
	}
	if(q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
	}
	else {
        q->front = q->front->next;
	}
	free(temp);
    return val;
}
