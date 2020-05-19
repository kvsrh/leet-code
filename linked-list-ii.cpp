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
    ListNode *detectCycle(ListNode *head) {
        
        ListNode * slow = NULL;
        ListNode * fast = NULL;
        
        int size = 0;
        
        while (fast != slow) {
            slow = slow->next;
            fast = (fast != NULL && fast->next != NULL) ? fast->next->next : NULL;
            if (slow == fast) {
                do {
                    size++;
                    slow = slow->next;
                } while (fast != slow);
                break;
            }
        }
        
        slow = head;
        fast = head;
        
        while (size > 0) {
            fast = fast->next;
            size--;
        }
        
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
       
        return slow;
        
    }
};
