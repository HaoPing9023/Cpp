//#define _CRT_SECURE_NO_WARNINGS 1
////对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
////给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//
//#include<iostream>
//using namespace std;
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//class PalindromeList {
//public:
//
//    ListNode* reverseNode(ListNode* A)
//    {
//        ListNode* prev = nullptr;
//        ListNode* cur = A;
//        while (cur)
//        {
//            ListNode* next = cur->next;
//            cur->next = prev;
//            prev = cur;
//            cur = next;
//        }
//        return prev;
//    }
//    bool chkPalindrome(ListNode* A) {
//        ListNode* fast = A;
//        ListNode* slow = A;
//        while (fast->next && fast->next->next)
//        {
//            fast = fast->next->next;
//            slow = slow->next;
//        }
//        ListNode* p2 = reverseNode(slow->next);
//        ListNode* p1 = A;
//        while (p2)
//        {
//            if (p1->val != p2->val)
//                return false;
//            p1 = p1->next;
//            p2 = p2->next;
//        }
//        return true;
//    }
//};
//ListNode* createList(initializer_list<int> arr) {
//    ListNode dummy(0);
//    ListNode* tail = &dummy;
//
//    for (int x : arr) {
//        tail->next = new ListNode(x);
//        tail = tail->next;
//    }
//
//    return dummy.next;
//}
//
//void printList(ListNode* head) {
//    while (head) {
//        cout << head->val;
//        if (head->next) cout << " -> ";
//        head = head->next;
//    }
//    cout << endl;
//}
//
//
//int main()
//{
//    PalindromeList solver;
//    ListNode* t1 = createList({ 1,2,2,1 });
//    ListNode* t2 = createList({ 1,2,3,2,1 });
//    ListNode* t3 = createList({ 1,2,3 });
//    ListNode* t4 = createList({ 1 });
//    ListNode* t5 = createList({ 1,2 });
//
//    cout << "测试用例 1：";
//    printList(t1);
//    cout << (solver.chkPalindrome(t1) ? "回文" : "不是回文") << endl;
//
//    cout << "测试用例 2：";
//    printList(t2);
//    cout << (solver.chkPalindrome(t2) ? "回文" : "不是回文") << endl;
//
//    cout << "测试用例 3：";
//    printList(t3);
//    cout << (solver.chkPalindrome(t3) ? "回文" : "不是回文") << endl;
//
//    cout << "测试用例 4：";
//    printList(t4);
//    cout << (solver.chkPalindrome(t4) ? "回文" : "不是回文") << endl;
//
//    cout << "测试用例 5：";
//    printList(t5);
//    cout << (solver.chkPalindrome(t5) ? "回文" : "不是回文") << endl;
//
//    return 0;
//}