//160.相交链表
//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
//如果两个链表不存在相交节点，返回 null 。

#include"Algorithm_150.h"

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* pA = headA;
        ListNode* pB = headB;
        while (pA != pB)
        {
            pA = pA != nullptr ? pA->next : headB;
            pB = pB != nullptr ? pB->next : headA;
        }
        return pA;
    }
};