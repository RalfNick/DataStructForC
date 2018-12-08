//
//  main.c
//  Algorithm
//
//  Created by wanglixin on 2018/12/1.
//  Copyright © 2018年 wanglixin. All rights reserved.
//

#include <stdio.h>
#include "sort_lib.h"

int main(int argc, const char * argv[]) {
    
    int arr[8] = {2,6,3,4,8,0,1,9};
    printf("---------------bubble sort begin----------------\n");
    printArray(arr, 8);
    
    printf("---------------bubble sort end----------------\n");
    bubbleSort(arr, 8);
    printArray(arr, 8);

    
    return 0;
}
