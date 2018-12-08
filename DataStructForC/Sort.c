//
//  BubbleSort.c
//  DataStructForC
//
//  Created by wanglixin on 2018/11/30.
//  Copyright © 2018年 wanglixin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"

// 交换
void swapArray(int *arr,int a,int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void printArray(int arr[],int length){
    if (arr == NULL) {
        return;
    }
    printf("[");
    for (int i = 0; i < length; i++) {
        if (i == length - 1) {
            printf("%d",i);
        }
        else{
            printf("%d,",i);
        }
    }
    printf("]\n");
}

// 冒泡排序
void bubbleSort(int arr[],int length){
    
    if (arr == NULL) {
        return;
    }
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 -i; j++) {
            if (arr[i] > arr[i+1]) {
                swapArray(arr,i, i+1);
            }
        }
    }
}

