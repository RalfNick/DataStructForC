//
//  stack.h
//  DataStructForC
//
//  Created by wanglixin on 2018/12/3.
//  Copyright © 2018年 wanglixin. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdbool.h>

typedef struct _array_stack
{
    int size;/*栈的大小*/
    int pos;/*当前存储元素的个数，即栈顶元素下表*/
    int *array;/*数据存储区*/
}ArrayStack;

#define DEFAULT_SIZE 10

ArrayStack * createStackDef();

ArrayStack * createStack(int size);

int pop(ArrayStack * stack);

bool push(ArrayStack * stack,int val);

bool pushExt(ArrayStack * stack,int val);

bool isEmptyStack(ArrayStack * stack);

bool isFullStack(ArrayStack * stack);

int size(ArrayStack * stack);

int peek(ArrayStack * stack);

void ensureCapacity(ArrayStack * stack,int length);

void printStack(ArrayStack * stack);

void testStack();

#endif /* stack_h */
