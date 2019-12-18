Reverse Linked List

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL


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
    
    // Replace each node in place. Recursive solution. 
    
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode * node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
        
    }
    
    // Iterative approach - 
    
    ListNode * reverseList(ListNode * head) {
        ListNode * curr = NULL;
        while (head != NULL) {
            ListNode * next = head->next;
            head->next = curr;
            curr = head;
            head = next;
        }
        return curr;
    }    
};
