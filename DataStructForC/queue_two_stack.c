//
//  queue_two_stack.c
//  DataStructForC
//
//  Created by wanglixin on 2018/12/17.
//  Copyright © 2018年 wanglixin. All rights reserved.
//

#include "queue_two_stack.h"
#include<stdlib.h>
#include <string.h>

QueueTwoStack * createStackQueueDef(){
    return createStackQueue(DEFAULT_SIZE);
}

QueueTwoStack * createStackQueue(int size){
    if (size < 1) {
        size = DEFAULT_SIZE;
    }
    QueueTwoStack * stackQueue = (QueueTwoStack *)malloc(sizeof(QueueTwoStack));
    if (stackQueue == NULL) {
        return NULL;
    }
    stackQueue->stack1 = createStack(size);
    if (stackQueue->stack1 == NULL) {
        free(stackQueue);
        return NULL;
    }
    stackQueue->stack2 = createStack(size);
    if (stackQueue->stack2 == NULL) {
        free(stackQueue);
        return NULL;
    }
    return stackQueue;
}

bool enQueueTwoStack(QueueTwoStack *queue,int val){
    if (isFullQueueTwoStack(queue)) {
        return false;
    }
    return push(queue->stack1, val);
}

int deQueueTwoStack(QueueTwoStack *queue){
    if (isEmptyQueueTwoStack(queue)) {
        return -1;
    }
    if (!isEmptyStack(queue->stack2)) {
        return pop(queue->stack2);
    }
    while (!isEmptyStack(queue->stack1)) {
        push(queue->stack2, pop(queue->stack1));
    }
    return pop(queue->stack2);
}

int sizeOfQueueTwoStack(QueueTwoStack *queue){
    if (queue == NULL) {
        return 0;
    }
    return size(queue->stack1) + size(queue->stack2);
}

int peekOfQueueTwoStack(QueueTwoStack *queue){
    if (isEmptyQueueTwoStack(queue)) {
        return -1;
    }
    if (!isEmptyStack(queue->stack2)) {
        return peek(queue->stack2);
    }
    while (!isEmptyStack(queue->stack1)) {
        push(queue->stack2, pop(queue->stack1));
    }
    return peek(queue->stack2);
}

bool isEmptyQueueTwoStack(QueueTwoStack *queue){
    if (queue == NULL) {
        return true;
    }
    return isEmptyStack(queue->stack1) && isEmptyStack(queue->stack2);
}

bool isFullQueueTwoStack(QueueTwoStack *queue){
    return size(queue->stack1) + size(queue->stack2) == queue->stack1->size;
}

void printQueueTwoStack(QueueTwoStack * queue){
    if (queue == NULL) {
        return;
    }
    if (!isEmptyStack(queue->stack2)) {
        for (int i = 0; i < size(queue->stack2); i++) {
            printf(" %d ",queue->stack2->array[i]);
        }
    }
    
    if (!isEmptyStack(queue->stack1)) {
        for (int i = 0; i < size(queue->stack1); i++) {
            printf(" %d ",queue->stack1->array[i]);
        }
    }
    printf("\n");
}

void testQueueTwoStack(){
    QueueTwoStack * queue = createStackQueue(10);
    QueueTwoStack * queue1 = createStackQueueDef();
    printf(" queue is empty: %d \n",isEmptyQueueTwoStack(queue));
    
    for (int i = 0; i < 10; i++) {
        enQueueTwoStack(queue, i);
        enQueueTwoStack(queue1, i+1);
    }
    printQueueTwoStack(queue);
    
    printf(" queue is full: %d \n",isFullQueueTwoStack(queue));
    printf(" queue size is : %d \n",sizeOfQueueTwoStack(queue));
    printf("---------------peek----------------\n");
    for (int i = 0; i < 10; i++) {
        printf(" peek is : %d \n",peekOfQueueTwoStack(queue));
        deQueueTwoStack(queue);
    }
    printf("---------------dequeue----------------\n");
    for (int i = 0; i < 10; i++) {
        printf(" dequeue is : %d \n",deQueueTwoStack(queue1));
    }
}

