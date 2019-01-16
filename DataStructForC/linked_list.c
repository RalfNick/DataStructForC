//
//  linked_list.c
//  DataStructForC
//
//  Created by wanglixin on 2018/12/26.
//  Copyright © 2018年 wanglixin. All rights reserved.
//


#include "linked_list.h"
#include <stdlib.h>
#include <string.h>

void create_linked_list(LinkedList* list){
    // 头结点
    *list = (LinkedList)malloc(sizeof(LinkedListNode));
    if (list == NULL) {
        return;
    }
    (*list)->val = -1;
    (*list)->next = NULL;
}

int size_linked_list(LinkedList list){
    if (!list) {
        return 0;
    }
    int i = 0;
    LinkedList current = list->next;
    while (current) {
        current = current->next;
        i++;
    }
    return i;
}

bool is_empty_linked_list(LinkedList list){
    if (!list || !list->next) {
        return true;
    }
    return false;
}

bool is_contain_linked_list(LinkedList list,int val){
    if (is_empty_linked_list(list)) {
        return false;
    }
    LinkedList current = list->next;
    while (current) {
        if (current->val == val) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// 尾部插入
bool add_linked_list(LinkedList list,int val){
    if (!list) {
        return false;
    }
    LinkedList current = list;
    // 找到最后一个节点
    while (current->next != NULL) {
        current = current->next;
    }
    LinkedList newNode = (LinkedList)malloc(sizeof(LinkedList));
    if (newNode == NULL) {
        free(list);
        return false;
    }
    newNode->val = val;
    newNode->next = NULL;
    current->next = newNode;
    return true;
}

void add_index_linked_list(LinkedList* list,int index,int val){
    
    if (!list) {
        create_linked_list(list);
    }
    LinkedList current = *list;
    int i = 0;
    while (current && i < index) {
        current = current->next;
        i++;
    }
    if (!current || i > index) {
        return;
    }
    LinkedList newNode = (LinkedList)malloc(sizeof(LinkedList));
    if (newNode == NULL) {
        free(list);
        return;
    }
    
    newNode->val = val;
    newNode->next = current->next;
    current->next = newNode;
}

int set_linked_list(LinkedList list,int index,int val){
    if (is_empty_linked_list(list)) {
        return -1;
    }
    LinkedList current = list->next;
    int i = 0;
    while (current && i < index) {
        current = current->next;
        i++;
    }
    if (!current || i > index) {
        return -1;
    }
    int oldVal = current->val;
    current->val = val;
    return oldVal;
}

int get_linked_list(LinkedList list,int index){
    if (is_empty_linked_list(list)) {
        return -1;
    }
    LinkedList current = list->next;
    int i = 0;
    while (current && i < index) {
        current = current->next;
        i++;
    }
    if (!current || i > index) {
        return -1;
    }
    return current->val;
}

bool remove_linked_list(LinkedList* list,int val){
    if (is_empty_linked_list(*list)) {
        return false;
    }
    int index = indexOf(*list, val);
    if (index == -1) {
        return false;
    }
    int result = remove_index_linked_list(list, index);
    if (result != val) {
        return false;
    }
    return true;
}

int remove_last_linked_list(LinkedList* list){
    if (is_empty_linked_list(*list)) {
        return -1;
    }
    LinkedList current = *list;
    int size = size_linked_list(*list);
    int index = 0;
    // 找到最后一个节点的前一个节点
    while (current && index < size - 1) {
        current = current->next;
        index++;
    }
    if (!current->next || index > size - 1) {
        return -1;
    }
    LinkedList node = current->next;
    int val = node->val;
    current->next = NULL;
    free(node);
    return val;
}

int remove_index_linked_list(LinkedList* list,int index){
    if (is_empty_linked_list(*list)) {
        return -1;
    }
    int i = 0;
    LinkedList current = *list;
    while (current && i < index) {
        current = current->next;
        i++;
    }
    if (!current || !current->next || i > index) {
        return -1;
    }
    LinkedList node = current->next;
    int result = node->val;
    current->next = node->next;
    node->next = NULL;
    free(node);
    return result;
}

void clear_linked_list(LinkedList* list){
    if (is_empty_linked_list(*list)) {
        return;
    }
    LinkedList current = (*list)->next;
    while (current) {
        LinkedList node = current;
        current = current->next;
        node->next = NULL;
        free(node);
    }
    (*list)->next = NULL;
}

int indexOf(LinkedList list,int val){
    if (is_empty_linked_list(list)) {
        return -1;
    }
    
    int i = 0;
    LinkedList current = list->next;
    while (current) {
        if (current->val == val) {
            return i;
        }
        i++;
        current = current->next;
    }
    return -1;
}

void print_linked_list(LinkedList list){
    if (is_empty_linked_list(list)) {
        return;
    }
    LinkedList current = list->next;
    while (current) {
        printf("%d ",current->val);
        current = current->next;
    }
    printf("\n");
}

void test_linked_list(){
    
    LinkedList list,list1;
    create_linked_list(&list);
    create_linked_list(&list1);
    
    printf(" linked list is empty: %d \n",is_empty_linked_list(list));
    printf(" linked list size is : %d \n",size_linked_list(list));
    
    for (int i = 0; i < 10; i++) {
        add_linked_list(list, i);
        add_linked_list(list1, i);
    }
    printf(" linked size is : %d \n",size_linked_list(list));
    print_linked_list(list);
    
    printf(" is_contain_linked_list - 5 : %d \n",is_contain_linked_list(list,5));
    printf(" is_contain_linked_list - 0 : %d \n",is_contain_linked_list(list,0));
    printf(" is_contain_linked_list - 9 : %d \n",is_contain_linked_list(list,9));
    printf(" is_contain_linked_list - 10 : %d \n",is_contain_linked_list(list,10));
    
    for (int i = 0; i < 10; i++) {
        printf("index of %d is %d\n",i,indexOf(list, i));
    }
    printf("index of 10 id %d \n",indexOf(list, 10));
    
    for (int i = 0; i < 10; i++) {
        printf("get index  %d is %d\n",i,get_linked_list(list, i));
    }
    printf("get index  %d is %d\n",10,get_linked_list(list, 10));
    
    add_index_linked_list(&list, 5, 11);
    print_linked_list(list);
    
    printf("set linked list index 0 to 10,old value is %d\n",set_linked_list(list, 0,10));
    
    print_linked_list(list);
    
    for (int i = 0; i < 10; i++) {
        printf("remove last,value is %d\n",remove_last_linked_list(&list));
    }
    print_linked_list(list);

    print_linked_list(list1);
    printf("remove index ,value is %d\n",remove_index_linked_list(&list1,5));
    printf("remove index ,value is %d\n",remove_index_linked_list(&list1,13));
    print_linked_list(list1);
//    for (int i = 0; i < 10; i++) {
//        remove_linked_list(&list1,i);
//        print_linked_list(list1);
//    }
    clear_linked_list(&list);
    printf("size of list is %d\n",size_linked_list(list));
    printf(" linked list is empty: %d \n",is_empty_linked_list(list));
    print_linked_list(list);
}

