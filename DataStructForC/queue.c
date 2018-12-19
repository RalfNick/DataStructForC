//
//  queue.c
//  DataStructForC
//
//  Created by wanglixin on 2018/12/11.
//  Copyright © 2018年 wanglixin. All rights reserved.
//

#include "queue.h"
#include<stdlib.h>
#include <string.h>

CircleQueue * createQueueDef(){
    return createQueue(DEFAULT_SIZE);
}

CircleQueue * createQueue(int size){
    if (size < 1) {
        size = DEFAULT_SIZE;
    }
    
    CircleQueue * queue = (CircleQueue *)malloc(sizeof(CircleQueue));
    if (queue == NULL) {
        free(queue);
        return NULL;
    }
    // 多分配一个位置
    queue->size = size + 1;
    queue->front = 0;
    queue->rear = 0;
    int * arr = (int *)malloc(sizeof(int) * queue->size);
    if (arr == NULL) {
        free(arr);
        return NULL;
    }
    queue->array = arr;
    return queue;
}

bool enQueue(CircleQueue *queue,int val){
    if (isFullQueue(queue)) {
        return false;
    }
    
    queue->array[queue->rear] = val;
    queue->rear = (queue->rear + 1) % queue->size;
    return true;
}

int deQueue(CircleQueue *queue){
    if (isEmptyQueue(queue)) {
        return -1;
    }
    int index = queue->front;
    queue->front = (queue->front + 1) % queue->size;
    return queue->array[index];
}

int sizeOfQueue(CircleQueue *queue){
    if (queue == NULL) {
        return 0;
    }
    return (queue->rear + queue->size - queue->front) % queue->size;
}

int peekOfQueue(CircleQueue *queue){
    if (isEmptyQueue(queue)) {
        return -1;
    }
    return queue->array[queue->front];
}

bool isEmptyQueue(CircleQueue *queue){
    if (queue == NULL) {
        return true;
    }
    return queue->front == queue->rear;
}

bool isFullQueue(CircleQueue *queue){
    if (queue == NULL) {
        return false;
    }
    return (queue->rear + 1) % queue->size == queue->front;
}

void printQueue(CircleQueue * queue){
    if (queue == NULL) {
        return;
    }
    for (int i=0; i < queue->size - 1; i++) {
        printf(" %d ",queue->array[i]);
    }
    printf("\n");
}

void testQueue(){
    CircleQueue * queue = createQueue(10);
    CircleQueue * queue1 = createQueueDef();
    printf(" queue is empty: %d \n",isEmptyQueue(queue));
    
    for (int i = 0; i < 10; i++) {
        enQueue(queue, i);
        enQueue(queue1, i+1);
    }
    printQueue(queue);
    
    printf(" queue is full: %d \n",isFullQueue(queue));
    printf(" queue size is : %d \n",sizeOfQueue(queue));
    printf("---------------peek----------------\n");
    for (int i = 0; i < 10; i++) {
        printf(" peek is : %d \n",peekOfQueue(queue));
        deQueue(queue);
    }
    printf("---------------dequeue----------------\n");
    for (int i = 0; i < 5; i++) {
        printf(" dequeue is : %d \n",deQueue(queue1));
    }
    printf("---------------dequeue and enQueue----------------\n");
    for (int i = 0; i < 5; i++) {
        enQueue(queue1,i);
        printf(" queue1 size is : %d \n",sizeOfQueue(queue1));
    }
    printQueue(queue1);
}

