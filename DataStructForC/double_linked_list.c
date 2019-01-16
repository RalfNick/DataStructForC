//
//  double_linked_list.c
//  DataStructForC
//
//  Created by wanglixin on 2019/1/14.
//  Copyright © 2019年 wanglixin. All rights reserved.
//

#include "double_linked_list.h"

#include <stdlib.h>
#include <string.h>

void create_dlinked_list(DLinkedList* list){
    // 头结点
    *list = (DLinkedList)malloc(sizeof(DLinkedListHead));
    if (list == NULL) {
        return;
    }
    (*list)->size = 0;
    (*list)->first = NULL;
    (*list)->last = NULL;
}

int size_dlinked_list(DLinkedList list){
    if (!list) {
        return 0;
    }
    return list->size;
}

bool is_empty_dlinked_list(DLinkedList list){
    return list->size == 0;
}

bool is_contain_dlinked_list(DLinkedList list,int val){
    if (!list || is_empty_dlinked_list(list)) {
        return false;
    }
    int index = indexOfDlinked(list, val);
    if (index == -1) {
        return false;
    }
    return true;
}

int indexOfDlinked(DLinkedList list,int val){
    if (!list || is_empty_dlinked_list(list)) {
        return -1;
    }
    int index = 0;
    ListNode f = list->first;
    while (f) {
        if (f->val == val) {
            return index;
        }
        f = f->next;
        index++;
    }
    return -1;
}

ListNode getListNodeByIndex(DLinkedList list,int index){
    if (!list || is_empty_dlinked_list(list) || index >= list->size) {
        return NULL;
    }
    int i = 0;
    ListNode f = list->first;
    while (f && i < index) {
        f = f->next;
        i++;
    }
    if(!f || i > index){
        return NULL;
    }
    return f;
}

bool add_dlinked_list(DLinkedList* list,int val){
    if (!list) {
        return false;
    }
    ListNode newNode = (ListNode)malloc(sizeof(DLinkedListNode));
    if (newNode == NULL) {
        free(list);
        return false;
    }
    newNode->next = NULL;
    newNode->val = val;
    (*list)->size++;
    ListNode l = (*list)->last;
    (*list)->last = newNode;
    newNode->prev = l;
    if (l == NULL) {
        (*list)->first = newNode;
    }
    else{
        l->next = newNode;
    }
    return true;
}

bool add_dlinked_list_first(DLinkedList* list,int val){
    if (!list) {
        return false;
    }
    ListNode newNode = (ListNode)malloc(sizeof(DLinkedListNode));
    if (newNode == NULL) {
        free(list);
        return false;
    }
    newNode->prev = NULL;
    newNode->val = val;
    (*list)->size++;
    ListNode f = (*list)->first;
    (*list)->first = newNode;
    newNode->next = f;
    if (f == NULL) {
        (*list)->last = newNode;
    }
    else{
        f->prev = newNode;
    }
    return true;
}

void add_index_dlinked_list(DLinkedList* list,int index,int val){
    if (!list || is_empty_dlinked_list(*list) || index > (*list)->size) {
        return;
    }
    if (index == 0) {
        add_dlinked_list_first(list, val);
    }
    else if (index == (*list)->size){
        add_dlinked_list(&(*list), val);
    }
    else{
        ListNode indexNode = getListNodeByIndex(*list,index);
        ListNode newNode = (ListNode)malloc(sizeof(DLinkedListNode));
        if (newNode == NULL) {
            free(list);
            return;
        }
        newNode->val = val;
        newNode->prev = indexNode->prev;
        newNode->next = indexNode;
        indexNode->prev->next = newNode;
        indexNode->prev = newNode;
        (*list)->size++;
    }
}

int set_dlinked_list(DLinkedList* list,int index,int val){
    if (!list || is_empty_dlinked_list(*list) || index >= (*list)->size) {
        return -1;
    }
    ListNode f = (*list)->first;
    int i = 0;
    while (f && i < index) {
        f = f->next;
        i++;
    }
    if (!f || i > index) {
        return -1;
    }
    int oldVal = f->val;
    f->val = val;
    return oldVal;
}

int get_dlinked_list(DLinkedList list,int index){
    if (!list || is_empty_dlinked_list(list) || index >= list->size) {
        return -1;
    }
    int i = 0;
    ListNode f = list->first;
    while (f && i < index) {
        f = f->next;
        i++;
    }
    if (!f || i > index) {
        return -1;
    }
    return f->val;
}

bool remove_dlinked_list(DLinkedList* list,int val){
    if (!list || is_empty_dlinked_list(*list)) {
        return false;
    }
    int index = indexOfDlinked(*list, val);
    if (index == -1) {
        return false;
    }
    remove_index_dlinked_list(list, index);
    return true;
}

int remove_first_dlinked_list(DLinkedList* list){
    if (!list || is_empty_dlinked_list(*list)) {
        return -1;
    }
    ListNode f = (*list)->first;
    int result = f->val;
    (*list)->first = f->next;
    if ((*list)->first == NULL) {
        (*list)->last = NULL;
    }
    else{
        (*list)->first->prev = NULL;
        f->next = NULL;
        free(f);
    }
    (*list)->size--;
    return result;
}

int remove_last_dlinked_list(DLinkedList* list){
    if (!list || is_empty_dlinked_list(*list)) {
        return -1;
    }
    ListNode l = (*list)->last;
    int result = l->val;
    (*list)->last = l->prev;
    if ((*list)->last == NULL) {
        (*list)->first = NULL;
    }
    else{
        (*list)->last->next = NULL;
        l->prev = NULL;
        free(l);
    }
    (*list)->size--;
    return result;
}

int remove_index_dlinked_list(DLinkedList* list,int index){
    if (!list || is_empty_dlinked_list(*list) || index >= (*list)->size) {
        return -1;
    }
    if (index == 0) {
        return remove_first_dlinked_list(list);
    }
    else if(index == (*list)->size - 1){
        return remove_last_dlinked_list(list);
    }
    else{
        ListNode node = getListNodeByIndex(*list, index);
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = NULL;
        node->prev = NULL;
        int result = node->val;
        free(node);
        return result;
    }
}

void clear_dlinked_list(DLinkedList* list){
    if (!list || is_empty_dlinked_list(*list)) {
        return;
    }

    ListNode node = (*list)->first;
    while (node) {
        ListNode temp = node->next;
        node->next = NULL;
        node->prev = NULL;
        free(node);
        node = temp;
    }
    (*list)->first = NULL;
    (*list)->last = NULL;
    (*list)->size = 0;
}

void print_dlinked_list(DLinkedList list){
    if (is_empty_dlinked_list(list)) {
        return;
    }
    for(ListNode current = list->first;current != NULL;current = current->next){
        int val = current->val;
        printf("%d ",val);
    }
    printf("\n");
}

void test_double_linked_list(){
    DLinkedList list = {0};
    DLinkedList list1 = {0};
    create_dlinked_list(&list);
    create_dlinked_list(&list1);
    
    printf(" double linked list is empty: %d \n",is_empty_dlinked_list(list));
    printf(" double linked list size is : %d \n",size_dlinked_list(list));
    
    for (int i = 0; i < 10; i++) {
        add_dlinked_list(&list, i);
        add_dlinked_list_first(&list1,i);
    }
    printf(" double linked list size is : %d \n",size_dlinked_list(list));
    print_dlinked_list(list);
    
    printf(" is_contain_linked_list - 5 : %d \n",is_contain_dlinked_list(list,5));
    printf(" is_contain_linked_list - 0 : %d \n",is_contain_dlinked_list(list,0));
    printf(" is_contain_linked_list - 9 : %d \n",is_contain_dlinked_list(list,9));
    printf(" is_contain_linked_list - 10 : %d \n",is_contain_dlinked_list(list,10));
    
    for (int i = 0; i < 10; i++) {
        printf("index of %d is %d\n",i,indexOfDlinked(list, i));
    }
    printf("index of 10 id %d \n",indexOfDlinked(list, 10));

    for (int i = 0; i < 10; i++) {
        printf("get index  %d is %d\n",i,get_dlinked_list(list1, i));
    }
    printf("get index  %d is %d\n",10,get_dlinked_list(list, 10));

    add_index_dlinked_list(&list, 5, 11);
    print_dlinked_list(list);

    printf("set linked list index 0 to 10,old value is %d\n",set_dlinked_list(&list, 0,10));

    print_dlinked_list(list);

    for (int i = 0; i < 10; i++) {
        printf("remove last,value is %d\n",remove_last_dlinked_list(&list));
    }
    print_dlinked_list(list);

    print_dlinked_list(list1);
//    printf("remove index ,value is %d\n",remove_index_dlinked_list(&list1,5));
//    printf("remove index ,value is %d\n",remove_index_dlinked_list(&list1,13));
//    print_dlinked_list(list1);
    for (int i = 0; i < 10; i++) {
        remove_dlinked_list(&list1,i);
        print_dlinked_list(list1);
    }
    clear_dlinked_list(&list);
    printf("size of list is %d\n",size_dlinked_list(list));
    printf(" linked list is empty: %d \n",is_empty_dlinked_list(list));
    print_dlinked_list(list);
}
