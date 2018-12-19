//
//  stack_two_queue.h
//  DataStructForC
//
//  Created by wanglixin on 2018/12/17.
//  Copyright © 2018年 wanglixin. All rights reserved.
//

#ifndef stack_two_queue_h
#define stack_two_queue_h

#include <stdio.h>
#include <stdbool.h>
#include "queue.h"

typedef struct _stack_two_queue
{
    CircleQueue *queue1;
    CircleQueue *queue2;
    
}StackTwoQueue;

#define DEFAULT_SIZE 10

StackTwoQueue * createStackTwoQueueDef();

StackTwoQueue * createStackTwoQueue(int size);

int popStackTwoQueue(StackTwoQueue * stack);

bool pushStackTwoQueue(StackTwoQueue * stack,int val);

bool isEmptyStackTwoQueue(StackTwoQueue * stack);

bool isFullStackTwoQueue(StackTwoQueue * stack);

int sizeOfStackTwoQueue(StackTwoQueue * stack);

int peekOfStackTwoQueue(StackTwoQueue * stack);

void printStackTwoQueue(StackTwoQueue * stack);

void testStackTwoQueue();


#endif /* stack_two_queue_h */
