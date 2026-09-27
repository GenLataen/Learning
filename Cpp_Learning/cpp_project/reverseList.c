#include <stdio.h>
#include <stdlib.h>

//定义链表节点
typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

//常见新节点
ListNode* createNode{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

//打印链表
void printfList(ListNode * head){
    printf("链表：");
    while(head){
        printf("%d -> ",head->val);
        head = head->next;
    }
    printf("NULL\n");
}

//从数组创建链表


//双指针原地反转
ListNode* reverseList(ListNode* head){
    if(head == NULL) return NULL;

    ListNode* prev = NULL;
    ListNode* curr = head；

    while(curr != NULL){
        List


    }
}
