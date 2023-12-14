#include "queue.h"


Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// 入队操作
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

// 出队操作
HPArb * dequeue(Queue* q) {
    if (q->front == NULL) {
        return NULL; // 队列为空
    }
    HPArb* data = q->front->data;
    QueueNode* temp = q->front;
    q->front = q->front->next;
    free(temp);
    if (q->front == NULL) {
        q->rear = NULL; // 队列已空
    }
    return data;
}