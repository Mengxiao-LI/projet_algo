//
// Created by lmx on 2023/12/14.
//

#ifndef PROJET_MENGXIAO_ZHENGDAO_QUEUE_H
#define PROJET_MENGXIAO_ZHENGDAO_QUEUE_H

#include "tasArbre.h"



typedef struct QueueNode {
    HPArb* data;
    struct QueueNode* next;
} QueueNode;


typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue();
void enqueue(Queue* q, HPArb* data);
HPArb * dequeue(Queue* q);
#endif //PROJET_MENGXIAO_ZHENGDAO_QUEUE_H
