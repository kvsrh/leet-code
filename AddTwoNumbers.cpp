//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode * dummyHead = new ListNode(0);
        ListNode * curr = dummyHead;
        ListNode *p = l1;
        ListNode *q = l2;
        int carry = 0;
        
        while (p != NULL || q != NULL) {
            int x = p != NULL ? p->val : 0;
            int y = q != NULL ? q->val : 0;
            int sum = (x+y+carry)%10;
            carry = (x+y+carry)/10;
            curr->next = new ListNode(sum);
            curr = curr->next;
            if (p != NULL) p = p->next;
            if (q != NULL) q = q->next;
        }
        
        if (carry  > 0) {
            curr->next = new ListNode(carry);
        }
        return dummyHead->next;
    }
};
