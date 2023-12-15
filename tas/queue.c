#include "queue.h"


Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}


void enqueue(Queue* q, HPArb* data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}


HPArb * dequeue(Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }
    HPArb* data = q->front->data;
    QueueNode* temp = q->front;
    q->front = q->front->next;
    free(temp);
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return data;
}
void freeQueue(Queue* q) {
    if (q == NULL) {
        return;
    }

    QueueNode* current = q->front;
    while (current != NULL) {
        QueueNode* temp = current;
        current = current->next;
        free(temp);
    }

    free(q);
}
