//206.反转链表
//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

#include"Algorithm_150.h"

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        struct ListNode* cur = head;
        struct ListNode* newNode = NULL;        //相当于前驱
        while (cur)
        {
            struct ListNode* temp = cur->next;
            cur->next = newNode;
            newNode = cur;
            cur = temp;
        }
        return newNode;
    }
};