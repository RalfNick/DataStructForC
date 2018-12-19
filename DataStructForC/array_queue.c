//
//  array_queue.c
//  DataStructForC
//
//  Created by wanglixin on 2018/12/16.
//  Copyright © 2018年 wanglixin. All rights reserved.
//

#include "array_queue.h"
#include<stdlib.h>
#include <string.h>

ArrayQueue * init_array_queue_def(){
    return init_array_queue(DEFAULT_SIZE);
}

ArrayQueue * init_array_queue(int size){
    if (size < 1) {
        size = DEFAULT_SIZE;
    }
    
    ArrayQueue * queue = (ArrayQueue *)malloc(sizeof(ArrayQueue));
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

bool array_enqueue(ArrayQueue *queue,int val){
    if (is_full_queue(queue)) {
        return false;
    }
    if (queue->rear == queue->size) {
        if (is_full_queue(queue)) {
            queue->front = 0;
            queue->rear = 0;
        }
        else{
            int temp = queue->front;
            for (int i = 0; i < size_array_queue(queue); i++) {
                queue->array[i] = queue->array[temp++];
            }
            queue->rear = size_array_queue(queue);
            queue->front = 0;
        }
    }
    queue->array[queue->rear++] = val;
    return true;
}

int array_dequeue(ArrayQueue *queue){
    if (is_empty_queue(queue)) {
        return -1;
    }
    return queue->array[queue->front++];
}

int size_array_queue(ArrayQueue *queue){
    if (is_empty_queue(queue)) {
        return 0;
    }
    return queue->rear - queue->front;
}

int peek_array_queue(ArrayQueue *queue){
    if (is_empty_queue(queue)) {
        return -1;
    }
    return queue->array[queue->front];
}

bool is_empty_queue(ArrayQueue *queue){
    if (queue == NULL || queue->front == queue->rear) {
        return true;
    }
    return false;
}

bool is_full_queue(ArrayQueue *queue){
    return size_array_queue(queue) == queue->size - 1;
}

void print_queue(ArrayQueue * queue){
    if (queue == NULL) {
        return;
    }
    for (int i=0; i < queue->size - 1; i++) {
        printf(" %d ",queue->array[i]);
    }
    printf("\n");
}

void test_queue(){
    ArrayQueue * queue = init_array_queue(10);
    ArrayQueue * queue1 = init_array_queue_def();
    printf(" queue is empty: %d \n",is_empty_queue(queue));
    
    for (int i = 0; i < 10; i++) {
        array_enqueue(queue, i);
        array_enqueue(queue1, i+1);
    }
    print_queue(queue);
    
    printf(" queue is full: %d \n",is_full_queue(queue));
    printf(" queue size is : %d \n",size_array_queue(queue));
    printf("---------------peek----------------\n");
    for (int i = 0; i < 10; i++) {
        printf(" peek is : %d \n",peek_array_queue(queue));
        array_dequeue(queue);
    }
    printf("---------------dequeue----------------\n");
    for (int i = 0; i < 10; i++) {
        printf(" dequeue is : %d \n",array_dequeue(queue1));
    }
}
