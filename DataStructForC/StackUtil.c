//
//  StackUtil.c
//  DataStructForC
//
//  Created by wanglixin on 2018/12/8.
//  Copyright © 2018年 wanglixin. All rights reserved.
//

#include "StackUtil.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void reverse(ArrayStack * stack){
    if (checkStackNull(stack)) {
        return;
    }
    int length = size(stack);
    ArrayStack * stack1 = createStack(length);
    ArrayStack * stack2 = createStack(length);
    
    while (!isEmptyStack(stack)) {
        push(stack1, pop(stack));
    }
    
    while (!isEmptyStack(stack1)) {
        push(stack2, pop(stack1));
    }
    
    while (!isEmptyStack(stack2)) {
        push(stack, pop(stack2));
    }
    
}

void removeStack(ArrayStack * stack,int val){
    if (checkStackNull(stack)) {
        return;
    }
    int length = size(stack);
    ArrayStack * stack1 = createStack(length);
    while (!isEmptyStack(stack) && peek(stack) != val) {
        push(stack1, pop(stack));
    }
    
    if (!isEmptyStack(stack)) {
        pop(stack);
    }
   
    while (!isEmptyStack(stack1)) {
        push(stack, pop(stack1));
    }
}

int* getTopStack(ArrayStack * stack,int* arr,int len){

    if (isEmptyStack(stack) || len < 1 || len > size(stack)) {
        return NULL;
    }

    ArrayStack * tempStack = createStack(size(stack));
    for (int i = 0; i < len; i++) {
        arr[i] = peek(stack);
        push(tempStack, pop(stack));
    }
    while (!isEmptyStack(tempStack)) {
        push(stack, pop(tempStack));
    }

    return arr;
}

bool checkStackNull(ArrayStack * stack){
    if (stack == NULL || stack->pos < 0) {
        return true;
    }
    return false;
}

void testStackUtil(){
    ArrayStack * stack = createStack(10);;
    
    printf("------------------init stack util-------------------\n");
    for (int i = 0; i < 10; i++) {
        push(stack, i);
    }
    printStack(stack);
    printf("------------------reverse stack-------------------\n");
    reverse(stack);
    printStack(stack);
    printf("------------------remove stack-------------------\n");
    
    removeStack(stack, 6);
    printStack(stack);
    
    removeStack(stack, 9);
    printStack(stack);
    
    removeStack(stack, 0);
    printStack(stack);
    
    printf("------------------get top stack-------------------\n");
    
    int arr[5];
    getTopStack(stack, arr, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    printStack(stack);
    
}
