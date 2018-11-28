//
//  Array.h
//  Algorithm
//
//  Created by wanglixin on 2018/11/20.
//  Copyright © 2018年 wanglixin. All rights reserved.
//

#ifndef Array_h
#define Array_h
#include <stdbool.h>

struct Array
{
    int len;
    int count;
    int *pArr;
};

typedef struct Array* List;

/**************************基本操作********************************/

void initArr(struct Array *pArr,int len);// 初始化数组
void initList(List list,int len);
bool addLast(struct Array *pArr,int val);//在数组后追加一个元素
bool insertArr(struct Array *pArr,int pos,int val);//指定位置插入元素
int removeIndex(struct Array *pArr,int pos);//指定位置删除元素
int removeArrVal(struct Array *pArr,int value);//删除指定元素，返回索引

bool isFull(struct Array *pArr);//判断数组是否满
bool isEmpty(struct Array *pArr);//判断数组是否空
void showArr(struct Array *pArr);//打印数组中的元素

int updateArr(struct Array *pArr,int pos,int val);//修改数组中的某个元素
int getElementPos(struct Array *pArr,int pos);// 查询指定位置元素
int getElementVal(struct Array *pArr,int value);// 查询特定值的元素，返回索引
int getSizeOfArr(struct Array *pArr);// 获取元素数量
void clearArr(struct Array *pArr);// 清空
bool contains(struct Array *pArr,int val);// 判断是否包含某个元素


/**************************算法相关********************************/

/**
 * 给定一个整形数组a , 对该数组的值进行置换
 * 例如： a = [7, 9 , 30, 3]  ,   置换后为 [3, 30, 9,7]
 * 如果     a = [7, 9, 30, 3, 4] , 置换后为 [4,3, 30 , 9,7]
 */
void reverseArr(List list);

/**
 * 现在有如下的一个数组：   int oldArr[]={1,3,4,5,0,0,6,6,0,5,4,7,6,7,0,5}
 * 要求将以上数组中值为0的项去掉，将不为0的值存入一个新的数组，生成的新数组为：
 * {1,3,4,5,6,6,5,4,7,6,7,5}
 */
List removeZero(List oldList);

/**
 * 给定两个已经排序好的整形数组， a1和a2 ,  创建一个新的数组a3, 使得a3 包含a1和a2 的所有元素， 并且仍然是有序的
 * 例如 a1 = [3, 5, 7,8]   a2 = [4, 5, 6,7]    则 a3 为[3,4,5,6,7,8]    , 注意： 已经消除了重复
 */
List merge(List list1,List list2);

/**
 * 把一个已经存满数据的数组 oldArray的容量进行扩展， 扩展后的新数据大小为oldArray.length + size
 * 注意，老数组的元素在新数组中需要保持
 * 例如 oldArray = [2,3,6] , size = 3,则返回的新数组为
 * [2,3,6,0,0,0]
 */
List grow(List oldList,int size);

/**
 * 斐波那契数列为：1，1，2，3，5，8，13，21......  ，给定一个最大值， 返回小于该值的数列
 * 例如， max = 15 , 则返回的数组应该为 [1，1，2，3，5，8，13]
 * max = 1, 则返回空数组 []
 */
List fibonacciList(int max);

/**
 * 返回小于给定最大值max的所有素数数组
 * 例如max = 23, 返回的数组为[2,3,5,7,11,13,17,19]
 */
List getPrimes(int max);

/**
 * 所谓“完数”， 是指这个数恰好等于它的因子之和，例如6=1+2+3
 * 给定一个最大值max， 返回一个数组， 数组中是小于max 的所有完数
 */
List getPerfectNumbers(int max);


#endif /* Array_h */

