//#define _CRT_SECURE_NO_WARNINGS 1
////给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
////如果两个链表不存在相交节点，返回 null 。
//#include<iostream>
//using namespace std;
//
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
// 
//class Solution {
//public:
//    //解法1：
//    ListNode* getIntersectionNode1(ListNode* headA, ListNode* headB) {
//        ListNode* longNode = headA;
//        ListNode* shortNode = headB;
//        int l = 0, s = 0;
//        //记录每段链表的长度
//        while (longNode->next)
//        {
//            longNode = longNode->next;
//            l++;
//        }
//        while (shortNode->next)
//        {
//            shortNode = shortNode->next;
//            s++;
//        }
//        //如果走到终点两个链表都不相等，说明没有相交的结点
//        if (longNode != shortNode) return NULL;
//        longNode = headA;
//        shortNode = headB;
//        //如果假设失败就互换
//        if (l < s)
//        {
//            longNode = headB;
//            shortNode = headA;
//        }
//        int k = l < s ? (s - l) : (l - s);
//        //长链表先走差值步
//        while (k--)
//            longNode = longNode->next;
//        //然后再同时走，如果遇到相同就返回
//        while (longNode && shortNode)
//        {
//            if (longNode == shortNode)
//                return longNode;
//            longNode = longNode->next;
//            shortNode = shortNode->next;
//        }
//        return NULL;
//    }
//
//    //解法2：
//    ListNode* getIntersectionNode2(ListNode* headA, ListNode* headB)
//    {
//        ListNode* pA = headA;
//        ListNode* pB = headB;
//        //如果a 走完就从 b 的头开始走，b也相同，最后ab走的步数一定相同
//        while (pA != pB)
//        {
//            pA = pA != nullptr ? pA->next : headB;
//            pB = pB != nullptr ? pB->next : headA;
//        }
//        return pA;
//    }
//};