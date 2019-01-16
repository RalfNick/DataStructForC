//
//  double_linked_list.h
//  DataStructForC
//
//  Created by wanglixin on 2019/1/14.
//  Copyright © 2019年 wanglixin. All rights reserved.
//

#ifndef double_linked_list_h
#define double_linked_list_h

#include <stdio.h>
#include <stdbool.h>

// 定义双向链表节点
typedef struct DLinkedListNode{
    int val; // 节点值
    struct DLinkedListNode * prev; // 下一个节点
    struct DLinkedListNode * next; // 下一个节点
}DLinkedListNode;

// 定义双向链表头节点
typedef struct DLinkedListHead{
    int size; // 节点值
    struct DLinkedListNode * first; // 头结点
    struct DLinkedListNode * last; // 尾节点
}DLinkedListHead;

typedef struct DLinkedListHead * DLinkedList; // 头结点，节点值用于存储长度

typedef struct DLinkedListNode * ListNode; // 头结点，节点值用于存储长度

void create_dlinked_list(DLinkedList* list);

int size_dlinked_list(DLinkedList list);

bool is_empty_dlinked_list(DLinkedList list);

bool is_contain_dlinked_list(DLinkedList list,int val);

bool add_dlinked_list(DLinkedList* list,int val);

bool add_dlinked_list_first(DLinkedList* list,int val);

void add_index_dlinked_list(DLinkedList* list,int index,int val);

int set_dlinked_list(DLinkedList* list,int index,int val);

ListNode getListNodeByIndex(DLinkedList list,int index);

int get_dlinked_list(DLinkedList list,int index);

bool remove_dlinked_list(DLinkedList* list,int val);

int remove_last_dlinked_list(DLinkedList* list);

int remove_first_dlinked_list(DLinkedList* list);

int remove_index_dlinked_list(DLinkedList* list,int index);

void clear_dlinked_list(DLinkedList* list);

int indexOfDlinked(DLinkedList list,int val);

void test_double_linked_list();

void print_dlinked_list(DLinkedList list);

#endif /* double_linked_list_h */
