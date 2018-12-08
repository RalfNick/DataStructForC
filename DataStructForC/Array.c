//
//  Array.c
//  Algorithm
//
//  Created by wanglixin on 2018/11/20.
//  Copyright © 2018年 wanglixin. All rights reserved.
//
#include "Array.h"
#include <string.h>

// 交换
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 初始化数组
void initArr(struct Array *pArr,int len){
    
    pArr->pArr = (int *)malloc(sizeof(int)*pArr->len);
    if (pArr->pArr == NULL) {
        printf("分配内存失败");
        exit(-1);   //终止程序
    }
    else{
        pArr->len = len;
        pArr->count = 0;
    }
}
void initList(List list,int len){
    
    list->pArr = (int *)malloc(sizeof(int)*list->len);
    if (list->pArr == NULL) {
        printf("分配内存失败");
        exit(-1);   //终止程序
    }
    else{
        list->len = len;
        list->count = 0;
    }
}

/*在数组后追加一个元素*/
bool addLast(struct Array *pArr,int val){
    if(pArr->pArr == NULL || pArr->len < 1 || isFull(pArr)){
        return false;
    }
    pArr->pArr[pArr->count] = val;
    pArr->count++;
    return true;
}


//指定位置插入元素
bool insertArr(struct Array *pArr,int pos,int val){
    if(pArr->pArr != NULL && !isFull(pArr) && pos < pArr->len && pos > -1){
        
        for (int i=pArr->count -1; i>=pos; i--) {
            pArr->pArr[i+1] = pArr->pArr[i];
        }
        pArr->pArr[pos] = val;
        pArr->count++;
        return true;
    }
    return false;
}

//指定位置删除元素
int removeIndex(struct Array *pArr,int pos){
    
    int val = -1;
    if(pArr != NULL && pos < pArr->count && pos > -1){
        val = pArr->pArr[pos];
        for (int i = pos; i< pArr->count; i++) {
            pArr->pArr[i] = pArr->pArr[i+1];
        }
        pArr->count--;
    }
    return val;
}

//删除指定元素，返回索引
int removeArrVal(struct Array *pArr,int value){
    
    int index = -1;
    if(!isEmpty(pArr)){
        index = getElementVal(pArr, value);
        if (index > -1) {
            removeIndex(pArr, index);
        }
    }
    return index;
}

//判断数组是否满
bool isFull(struct Array *pArr){
    if (pArr->count == pArr->len) {
        return true;
    }
    return false;
}

//判断数组是否空
bool isEmpty(struct Array *pArr){
    if (pArr->pArr == NULL || pArr->count < 1) {
        return true;
    }
    return false;
}

//打印数组中的元素
void showArr(struct Array *pArr){
    if (pArr != NULL && pArr->count > 0) {
        for (int i=0; i<pArr->count; i++) {
            printf("第 %d 个元素是： %d\n",i,pArr->pArr[i]);
        }
    }
    printf("元素总数： %d\n",pArr->count);
}

//修改数组中的某个元素
int updateArr(struct Array *pArr,int pos,int val){
    int oldVal = -1;
    if (pArr != NULL && pos < pArr->count) {
        oldVal = pArr->pArr[pos];
        pArr->pArr[pos] = val;
    }
    return oldVal;
}

// 查询元素
int getElementPos(struct Array *pArr,int pos){
    
    int val = -1;
    if (pArr != NULL && pos < pArr->count) {
        val = pArr->pArr[pos];
    }
    return val;
}

// 查询特定值的元素，返回索引
int getElementVal(struct Array *pArr,int value){
    int index = -1;
    if (!isEmpty(pArr)) {
        for (int i=0; i<pArr->count; i++) {
            if (value == pArr->pArr[i]) {
                index = i;
                break;
            }
        }
    }
    return index;
}

// 获取元素数量
int getSizeOfArr(struct Array *pArr){
    
    if (pArr != NULL) {
        return pArr->count;
    }
    return 0;
}

// 判断是否包含某个元素
bool contains(struct Array *pArr,int val){
    
    if (isEmpty(pArr)) {
        return false;
    }
    for (int i=0; i<pArr->count; i++) {
        if (val == pArr->pArr[i]) {
            return true;
        }
    }
    return false;
}

// 清空
void clearArr(struct Array *pArr){
    // 其实不用设置0
    if (pArr != NULL && pArr->count > 0) {
        for (int i=0; i<pArr->count; i++) {
            pArr->pArr[i] = 0;
        }
        pArr->count = 0;
    }
}

//倒置数组中的元素
void reverseArr(List list){
    if (isEmpty(list)) {
        return;
    }
    int count = list->count;
    for (int i=0; i<count/2; i++) {
        swap(&list->pArr[i], &list->pArr[count - 1 -i]);
    }
}

// 去除0元素
List removeZero(List oldList){
    if (isEmpty(oldList)) {
        return NULL;
    }
    List newList = (List)malloc(sizeof(struct Array));
    initArr(newList, oldList->len);
    for (int i=0; i<oldList->count; i++) {
        int val = oldList->pArr[i];
        if (val != 0) {
            addLast(newList, val);
        }
    }
    return newList;
}

// 合并两个数组
List merge(List list1,List list2){
    if (isEmpty(list1)) {
        return list2;
    }
    else if (isEmpty(list2)){
        return list1;
    }
    List mergeList = (List)malloc(sizeof(struct Array));
    mergeList->len = list1->count + list2->count;
    mergeList->pArr = (int *)malloc(sizeof(int)*mergeList->len);
    
    int index1 = 0;
    int index2 = 0;
    
    for (int i=0; i<mergeList->len; i++) {
        if (index1 == list1->count) {
            for (int j=index2; j<list2->count; j++) {
                addLast(mergeList, list2->pArr[j]);
            }
            break;
        }
        else if (index2 == list2->count){
            for (int j=index1; j<list1->count; j++) {
                addLast(mergeList, list1->pArr[j]);
            }
            break;
            
        }
        else{
            int num1 = list1->pArr[index1];
            int num2 = list2->pArr[index2];
            int result;
            if (num1 == num2) {
                result = num1;
                index1++;
                index2++;
            }
            else if (num1 < num2){
                result = num1;
                index1++;
            }
            else{
                result = num2;
                index2++;
            }
            addLast(mergeList, result);
        }
    }
    
    return mergeList;
}

// 扩容
List grow(List oldList,int size){
    
    if (isEmpty(oldList)) {
        return NULL;
    }
    List growList = (List)malloc(sizeof(struct Array));
    growList->len = oldList->count + size;
    growList->pArr = (int *)malloc(sizeof(int)*growList->len);
    
    for (int i = 0; i<oldList->count; i++) {
        addLast(growList, oldList->pArr[i]);
    }
    // 其他值赋为0
    for (int i = oldList->count; i< growList->len; i++) {
        addLast(growList, 0);
    }
    return growList;
}

void fibonacci(int a,int b,int max,List list){
    if (b > max) {
        return;
    }
    if (isFull(list)) {
        list = grow(list, list->len);
    }
    addLast(list, b);
    return fibonacci(b,a+b,max,list);
}

List fibonacciList(int max){
    if (max < 2) {
        return NULL;
    }
    List fibonacciList = (List)malloc(sizeof(struct Array));
    fibonacciList->len = max;
    fibonacciList->pArr = (int *)malloc(sizeof(int)*fibonacciList->len);
    addLast(fibonacciList, 1);
    fibonacci(1, 1, max, fibonacciList);
    return fibonacciList;
}

bool isPrime(int num){
    
    bool isPrime = true;
    for (int i=2; i<=num/2; i++) {
        if (num % i == 0) {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

/**
 * 返回小于给定最大值max的所有素数数组
 * 例如max = 23, 返回的数组为[2,3,5,7,11,13,17,19]
 */
List getPrimes(int max){
    if (max < 2) {
        return NULL;
    }
    
    List primeList = (List)malloc(sizeof(struct Array));
    primeList->len = max;
    primeList->pArr = (int *)malloc(sizeof(int)*primeList->len);
    for (int i=2; i<=max; i++) {
        if (isPrime(i)) {
            addLast(primeList, i);
        }
    }
    
    return primeList;
}

// 判断是否是完数
bool isPerfectNum(int num){
    
    int sum = 1;
    for (int i=2; i <= num/2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    if(num == sum){
        return true;
    }
    return false;
}
/**
 * 所谓“完数”， 是指这个数恰好等于它的因子之和，例如6=1+2+3
 * 给定一个最大值max， 返回一个数组， 数组中是小于max 的所有完数
 */
List getPerfectNumbers(int max){
    
    List perfectList = (List)malloc(sizeof(struct Array));
    perfectList->len = max;
    perfectList->pArr = (int *)malloc(sizeof(int)*perfectList->len);
    
    for (int i=2; i<=max; i++) {
        if (isPerfectNum(i)) {
            addLast(perfectList, i);
        }
    }
    return perfectList;
}
