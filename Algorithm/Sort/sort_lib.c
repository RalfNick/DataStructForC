//
//  sort_lib.c
//  Algorithm
//
//  Created by wanglixin on 2018/12/1.
//  Copyright © 2018年 wanglixin. All rights reserved.
//

#include "sort_lib.h"
#include <stdio.h>
#include <stdlib.h>

// 交换
void swapArray(int *arr,int a,int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void printArray(int* arr,int length){
    if (arr == NULL) {
        return;
    }
    printf("[");
    for (int i = 0; i < length; i++) {
        if (i == length - 1) {
            printf("%d",arr[i]);
        }
        else{
            printf("%d,",arr[i]);
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
            if (arr[j] > arr[j+1]) {
                swapArray(arr,j, j+1);
            }
        }
    }
}


