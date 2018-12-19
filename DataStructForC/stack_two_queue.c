//
//  stack_two_queue.c
//  DataStructForC
//
//  Created by wanglixin on 2018/12/17.
//  Copyright © 2018年 wanglixin. All rights reserved.
//

#include "stack_two_queue.h"
#include <stdio.h>
#include<stdlib.h>

StackTwoQueue * createStackTwoQueueDef(){
    
    return createStackTwoQueue(DEFAULT_SIZE);
}

StackTwoQueue * createStackTwoQueue(int size){
    
    if (size < 1) {
        size = DEFAULT_SIZE;
    }
    StackTwoQueue * stack = (StackTwoQueue *)malloc(sizeof(StackTwoQueue));
    if (stack == NULL) {
        return NULL;
    }
    stack->queue1 = createQueue(size);
    if (stack->queue1 == NULL) {
        free(stack);
        return NULL;
    }
    stack->queue2 = createQueue(size);
    if (stack->queue2 == NULL) {
        free(stack);
        return NULL;
    }
    return stack;
}

int popStackTwoQueue(StackTwoQueue * stack){
    
    if (isEmptyStackTwoQueue(stack)) {
        return -1;
    }
    if (isEmptyQueue(stack->queue1)) {
        int length = sizeOfQueue(stack->queue2) - 1;
        for (int i = 0; i < length; i++) {
            enQueue(stack->queue1, deQueue(stack->queue2));
        }
        return deQueue(stack->queue2);
    }
    else{
        int length = sizeOfQueue(stack->queue1) - 1;
        for (int i = 0; i < length; i++) {
            enQueue(stack->queue2, deQueue(stack->queue1));
        }
        return deQueue(stack->queue1);
    }
}

bool pushStackTwoQueue(StackTwoQueue * stack,int val){
    if (stack == NULL) {
        return false;
    }
    if (isFullStackTwoQueue(stack)) {
        return false;
    }
    if (isEmptyQueue(stack->queue2)) {
        return enQueue(stack->queue1, val);
    }
    else{
        return enQueue(stack->queue2, val);
    }
    
}

bool isEmptyStackTwoQueue(StackTwoQueue * stack){
    if (stack == NULL) {
        return true;
    }
    return isEmptyQueue(stack->queue1) && isEmptyQueue(stack->queue2);
}

bool isFullStackTwoQueue(StackTwoQueue * stack){
    if (stack == NULL) {
        return false;
    }
    return isFullQueue(stack->queue1) || isFullQueue(stack->queue2);
}

int sizeOfStackTwoQueue(StackTwoQueue * stack){
    if (stack == NULL) {
        return 0;
    }
    if (isEmptyQueue(stack->queue1)) {
        return sizeOfQueue(stack->queue2);
    }
    if (isEmptyQueue(stack->queue2)) {
        return sizeOfQueue(stack->queue1);
    }
    return 0;
}

int peekOfStackTwoQueue(StackTwoQueue * stack){
    if (isEmptyStackTwoQueue(stack)) {
        return -1;
    }
    int result = -1;
    if (isEmptyQueue(stack->queue1)) {
        int length = sizeOfQueue(stack->queue2) - 1;
        for (int i = 0; i < length; i++) {
            enQueue(stack->queue1, deQueue(stack->queue2));
        }
        result = deQueue(stack->queue2);
        enQueue(stack->queue1, result);
    }
    else{
        int length = sizeOfQueue(stack->queue1) - 1;
        for (int i = 0; i < length; i++) {
            enQueue(stack->queue2, deQueue(stack->queue1));
        }
        result = deQueue(stack->queue1);
        enQueue(stack->queue2, result);
    }
    return result;
}

void printStackTwoQueue(StackTwoQueue * stack){
    if (isEmptyStackTwoQueue(stack)) {
        return;
    }
    if (isEmptyQueue(stack->queue1)) {
        printQueue(stack->queue2);
    }
    else{
        printQueue(stack->queue1);
    }
}

void testStackTwoQueue(){
    
    StackTwoQueue * stack = createStackTwoQueue(10);;
    
    printf("------------------init StackTwoQueue--------------------\n");
    for (int i = 0; i < 10; i++) {
        pushStackTwoQueue(stack, i);
        printStackTwoQueue(stack);
    }
    printf("stack size is %d \n",sizeOfStackTwoQueue(stack));
    printf("------------------isFullStack stack--------------------\n");
    printf("stack is isFullStack %d \n",isFullStackTwoQueue(stack));
    
    printf("------------------pop stack start-------------------\n");
    for (int i = 0; i < 10; i++) {
        printf("top item is %d \n",peekOfStackTwoQueue(stack));
        int top = popStackTwoQueue(stack);
//                printf("%d ",top);
    }
    printf("\n------------------pop stack end--------------------\n");
    printf("------------------isEmptyStack stack--------------------\n");
    printf("stack is isEmpty %d \n",isEmptyStackTwoQueue(stack));
    
    printf("stack size is %d \n",sizeOfStackTwoQueue(stack));
}


