//
//  array_queue.h
//  DataStructForC
//
//  Created by wanglixin on 2018/12/16.
//  Copyright © 2018年 wanglixin. All rights reserved.
//

/*
 * 顺序队列，非环形
 */
#ifndef array_queue_h
#define array_queue_h

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

ArrayQueue * init_array_queue_def();

ArrayQueue * init_array_queue(int size);

bool array_enqueue(ArrayQueue *queue,int val);

int array_dequeue(ArrayQueue *queue);

int size_array_queue(ArrayQueue *queue);

int peek_array_queue(ArrayQueue *queue);

bool is_empty_queue(ArrayQueue *queue);

bool is_full_queue(ArrayQueue *queue);

void print_queue(ArrayQueue *stack);

void test_queue();

#endif /* array_queue_h */
