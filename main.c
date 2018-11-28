//
//  main.c
//  Algorithm
//
//  Created by wanglixin on 2018/11/15.
//  Copyright © 2018年 wanglixin. All rights reserved.
//

# include <stdio.h>
# include <stdlib.h>
# include "Array.h"

int main(int argc, const char * argv[]) {
    
    struct Array arr,list;
    initArr(&arr, 10);
    initArr(&list, 10);
    
    for (int i=0; i<6;i++) {
        addLast(&arr, i);
        addLast(&list, i);
    }
    
    showArr(&arr);
    printf("-----------------\n");
    
    insertArr(&arr, 2, 100);
    showArr(&arr);
    printf("-----------------\n");
    
    removeIndex(&arr, 5);
    showArr(&arr);
    printf("-----------------\n");
    
    removeArrVal(&arr, 100);
    showArr(&arr);
    printf("-----------------\n");
    
    int index = getElementVal(&arr, 5);
    printf("5位置的索引  %d  \n",index);
    printf("-----------------\n");
    
    index = getElementVal(&arr, 100);
    printf("100位置的索引  %d  \n",index);
    printf("-----------------\n");
    
    int val = getElementPos(&arr, 2);
    printf("索引为2的元素  %d  \n",val);
    printf("-----------------\n");
    
    int oldVal = updateArr(&arr, 4, 100);
    printf("修改索引4位置的值为100，旧的值是  %d  \n",oldVal);
    showArr(&arr);
    printf("-----------------\n");
    
    
    int count = getSizeOfArr(&arr);
    printf("数组大小  %d  \n",count);
    printf("-----------------\n");
    
    printf("是否包含元素100  %d  \n",contains(&arr, 100));
    printf("-----------------\n");
    
    printf("是否为满 %d \n",isFull(&arr));
    printf("是否为空 %d \n",isEmpty(&arr));
    printf("-----------------\n");
    
    clearArr(&arr);
    showArr(&arr);
    printf("-----------------\n");
    
    printf("是否为满 %d \n",isFull(&arr));
    printf("是否为空 %d \n",isEmpty(&arr));
    printf("-----------------\n");

    /**************算法部分**************************/
    showArr(&list);
    printf("--------reverseArr Begin---------\n");
    reverseArr(&list);
    showArr(&list);
    printf("---------reverseArr End--------\n");
    
    // 添加0
    addLast(&list, 0);
    insertArr(&list, 3, 0);
    showArr(&list);
    printf("-------------------------------\n");
    
    // 移除0
    List nozeroList = removeZero(&list);
    showArr(nozeroList);
    printf("--------------移除0元素--------------\n");
    
    // 合并两个集合
    /**
     * 给定两个已经排序好的整形数组， a1和a2 ,  创建一个新的数组a3, 使得a3 包含a1和a2 的所有元素， 并且仍然是有序的
     * 例如 a1 = [3, 5, 7,8]   a2 = [4, 5, 6,7]    则 a3 为[3,4,5,6,7,8]    , 注意： 已经消除了重复
     */
    
    List list1 = (List)malloc(sizeof(struct Array));
    List list2 = (List)malloc(sizeof(struct Array));
    initList(list1,4);
    initList(list2, 4);
    
    addLast(list1, 3);
    addLast(list1, 5);
    addLast(list1, 7);
    addLast(list1, 8);
    addLast(list2, 4);
    addLast(list2, 5);
    addLast(list2, 6);
    addLast(list2, 7);
    
    showArr(list1);
    showArr(list2);
    showArr(merge(list1, list2));
    printf("--------------merge--------------\n");
    
    /**
     * 把一个已经存满数据的数组 oldArray的容量进行扩展， 扩展后的新数据大小为oldArray.length + size
     * 注意，老数组的元素在新数组中需要保持
     * 例如 oldArray = [2,3,6] , size = 3,则返回的新数组为
     * [2,3,6,0,0,0]
     */
    List list3 = (List)malloc(sizeof(struct Array));
    initList(list3,3);
    addLast(list3, 2);
    addLast(list3, 3);
    addLast(list3, 6);
    
    showArr(list3);
    showArr(grow(list3, 3));
    printf("--------------grow--------------\n");

    showArr(fibonacciList(15));
    printf("--------------fibonacciList--------------\n");
    
    showArr(getPrimes(23));
    printf("--------------getPrimes--------------\n");
    
    showArr(getPerfectNumbers(10000));
    printf("--------------getPerfectNumbers--------------\n");
    
    return 0;
}
