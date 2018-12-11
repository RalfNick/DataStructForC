//
//  queue.h
//  DataStructForC
//
//  Created by wanglixin on 2018/12/11.
//  Copyright © 2018年 wanglixin. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdbool.h>

typedef struct _array_queue
{
    int size;/*队列的大小*/
    int front;/*对列头位置*/
    int rear;/*对列尾位置*/
    int *array;/*数据存储区*/
}ArrayQueue;

#define DEFAULT_SIZE 10

ArrayQueue * createQueueDef();

ArrayQueue * createQueue(int size);

bool enQueue(ArrayQueue *queue,int val);

int deQueue(ArrayQueue *queue);

int sizeOfQueue(ArrayQueue *queue);

int peekOfQueue(ArrayQueue *queue);

bool isEmptyQueue(ArrayQueue *queue);

bool isFullQueue(ArrayQueue *queue);

void printQueue(ArrayQueue * stack);

void testQueue();

#endif /* queue_h */
