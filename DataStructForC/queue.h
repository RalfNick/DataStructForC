//
//  queue.h
//  DataStructForC
//
//  Created by wanglixin on 2018/12/11.
//  Copyright © 2018年 wanglixin. All rights reserved.
//
/*
 * 环形队列
 */
#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdbool.h>

typedef struct _circle_queue
{
    int size;/*队列的大小*/
    int front;/*对列头位置*/
    int rear;/*对列尾位置*/
    int *array;/*数据存储区*/
}CircleQueue;

#define DEFAULT_SIZE 10

CircleQueue * createQueueDef();

CircleQueue * createQueue(int size);

bool enQueue(CircleQueue *queue,int val);

int deQueue(CircleQueue *queue);

int sizeOfQueue(CircleQueue *queue);

int peekOfQueue(CircleQueue *queue);

bool isEmptyQueue(CircleQueue *queue);

bool isFullQueue(CircleQueue *queue);

void printQueue(CircleQueue * stack);

void testQueue();

#endif /* queue_h */
