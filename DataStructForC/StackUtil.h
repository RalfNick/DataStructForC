//
//  StackUtil.h
//  DataStructForC
//
//  Created by wanglixin on 2018/12/8.
//  Copyright © 2018年 wanglixin. All rights reserved.
//

#ifndef StackUtil_h
#define StackUtil_h

#include <stdio.h>
#include "stack.h"
#include <stdbool.h>

/**
 * 假设栈中的元素是Integer, 从栈顶到栈底是 : 5,4,3,2,1 调用该方法后， 元素次序变为: 1,2,3,4,5
 * 注意：只能使用Stack的基本操作，即push,pop,peek,isEmpty， 可以使用另外一个栈来辅助
 */
void reverse(ArrayStack * stack);

/**
 * 删除栈中的某个元素 注意：只能使用Stack的基本操作，即push,pop,peek,isEmpty， 可以使用另外一个栈来辅助
 */
void removeStack(ArrayStack * stack,int val);

/**
 * 从栈顶取得len个元素, 原来的栈中元素保持不变
 * 注意：只能使用Stack的基本操作，即push,pop,peek,isEmpty， 可以使用另外一个栈来辅助
 */
int* getTopStack(ArrayStack * stack,int* arr,int len);

bool checkStackNull(ArrayStack * stack);

void testStackUtil();

#endif /* StackUtil_h */
