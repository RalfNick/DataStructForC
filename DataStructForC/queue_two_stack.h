//
//  queue_two_stack.h
//  DataStructForC
//
//  Created by wanglixin on 2018/12/17.
//  Copyright © 2018年 wanglixin. All rights reserved.
//

#ifndef queue_two_stack_h
#define queue_two_stack_h

#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

#define DEFAULT_SIZE 10

typedef struct _queue_two_stack{
    
    ArrayStack *stack1; // 进队列的栈
    ArrayStack *stack2; // 出队列的栈
    
}QueueTwoStack;

QueueTwoStack * createStackQueueDef();

QueueTwoStack * createStackQueue(int size);

bool enQueueTwoStack(QueueTwoStack *queue,int val);

int deQueueTwoStack(QueueTwoStack *queue);

int sizeOfQueueTwoStack(QueueTwoStack *queue);

int peekOfQueueTwoStack(QueueTwoStack *queue);

bool isEmptyQueueTwoStack(QueueTwoStack *queue);

bool isFullQueueTwoStack(QueueTwoStack *queue);

void printQueueTwoStack(QueueTwoStack * stack);

void testQueueTwoStack();

#endif /* queue_two_stack_h */
