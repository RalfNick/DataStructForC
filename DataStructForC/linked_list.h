//
//  linked_list.h
//  DataStructForC
//
//  Created by wanglixin on 2018/12/26.
//  Copyright © 2018年 wanglixin. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>
#include <stdbool.h>

// 定义单链表节点
typedef struct LinkedListNode{
    int val; // 节点值
    struct LinkedListNode * next; // 下一个节点
}LinkedListNode;

typedef struct LinkedListNode * LinkedList;

void create_linked_list(LinkedList* list);

int size_linked_list(LinkedList list);

bool is_empty_linked_list(LinkedList list);

bool is_contain_linked_list(LinkedList list,int val);

bool add_linked_list(LinkedList list,int val);

void add_index_linked_list(LinkedList* list,int index,int val);

int set_linked_list(LinkedList list,int index,int val);

int get_linked_list(LinkedList list,int index);

bool remove_linked_list(LinkedList* list,int val);

int remove_last_linked_list(LinkedList* list);

int remove_index_linked_list(LinkedList* list,int index);

void clear_linked_list(LinkedList* list);

int indexOf(LinkedList list,int val);

void test_linked_list();

void print_linked_list(LinkedList list);

#endif /* linked_list_h */
