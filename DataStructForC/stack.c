//
//  stack.c
//  DataStructForC
//
//  Created by wanglixin on 2018/12/3.
//  Copyright © 2018年 wanglixin. All rights reserved.
//

#include "stack.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

ArrayStack * createStack(int size){
    
    ArrayStack * stack = NULL;
    if (size < 1) {
        size = DEFAULT_SIZE;
    }
    stack = (ArrayStack *)malloc(sizeof(ArrayStack));
    if (stack == NULL) {
        return NULL;
    }
    stack->pos = -1;
    stack->size = size;
    stack->array = (int *)malloc(sizeof(int) * size);
    if (stack->array == NULL) {
        free(stack);
        return NULL;
    }
    return stack;
}

ArrayStack * createStackDef(){
    return createStack(DEFAULT_SIZE);
}

int pop(ArrayStack * stack){
    if (isEmptyStack(stack)) {
        return -1;
    }
    return stack->array[stack->pos--];
}

bool push(ArrayStack * stack,int val){
    if (stack == NULL || isFullStack(stack)) {
        return false;
    }
    stack->pos++;
    stack->array[stack->pos] = val;
    return true;
}

bool pushExt(ArrayStack * stack,int val){
    if (stack == NULL) {
        stack = createStack(DEFAULT_SIZE);
        return push(stack, val);
    }
    else if (isFullStack(stack)) {
        ensureCapacity(stack,stack->size);
        return push(stack, val);
    }
    else{
        return push(stack, val);
    }
}

bool isEmptyStack(ArrayStack * stack){
    if (stack == NULL || stack->pos < 0) {
        return true;
    }
    return false;
}

bool isFullStack(ArrayStack * stack){
    if (stack == NULL) {
        return false;
    }
    if (stack->pos == stack->size - 1) {
        return true;
    }
    return false;
}

int size(ArrayStack * stack){
    if (isEmptyStack(stack)) {
        return 0;
    }
    return stack->pos + 1;
}

int peek(ArrayStack * stack){
    if (isEmptyStack(stack)) {
        return -1;
    }
    return stack->array[stack->pos];
}

void ensureCapacity(ArrayStack * stack,int length){
    if (length < 1) {
        return;
    }
    int *newArr = NULL;
    newArr = (int *)malloc(sizeof(int) * stack->size * (stack->size + length));
    if (newArr == NULL) {
        return;
    }
    memcpy(newArr,stack->array,stack->size * sizeof(int));
    free(stack->array);
    stack->size += length;
    stack->array = newArr;
}

void printStack(ArrayStack * stack){
    if (isEmptyStack(stack)) {
        return;
    }
    for (int i = 0; i <= stack->pos; i++) {
        printf("%d ",stack->array[i]);
    }
     printf("\n");
}

void testStack(){
    
    ArrayStack * stack = createStack(10);;

    printf("------------------init stack--------------------\n");
    for (int i = 0; i < 10; i++) {
        push(stack, i);
        printStack(stack);
    }
    printf("stack size is %d \n",size(stack));
    printf("------------------isFullStack stack--------------------\n");
    printf("stack is isFullStack %d \n",isFullStack(stack));
    
    printf("------------------pop stack start-------------------\n");
    for (int i = 0; i < 10; i++) {
        printf("top item is %d \n",peek(stack));
        int top = pop(stack);
//        printf("%d ",top);
    }
    printf("\n------------------pop stack end--------------------\n");
    printf("------------------isEmptyStack stack--------------------\n");
    printf("stack is isEmpty %d \n",isEmptyStack(stack));
    
    for (int i = 0; i < 20; i++) {
        pushExt(stack, i);
        printStack(stack);
    }
    printf("stack size is %d \n",size(stack));
}
