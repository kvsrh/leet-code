// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the
// nodes of the first two lists.

// Example:

// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode * dummyHead = new ListNode(0);
        ListNode * curr = dummyHead;
        ListNode * p = l1;
        ListNode * q = l2;

        
        while (p != NULL && q != NULL) {
            int x = p->val;
            int y = q->val;
            
            if (x<y) {
                curr->next = new ListNode(x);
                curr = curr->next;
                p = p->next;
            } else {
                curr->next = new ListNode(y);
                curr = curr->next;
                q = q->next;
            }
        }
        
        if (q != NULL) {
            curr->next = q;            
        } else if (p != NULL) {
            curr->next = p;
        }
        
        return dummyHead->next;
    }
};
