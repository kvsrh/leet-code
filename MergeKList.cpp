Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


bool compare (ListNode * a, ListNode * b) {
    return a->val > b->val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode * dummy_head = new ListNode(0);
        
        int row_size = lists.size();
        
        if (row_size == 0) return NULL;
        
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode* a, ListNode* b)>> pq(compare);
        
        for (int i = 0; i < row_size; i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        
        ListNode * tail = dummy_head;
        
        // cout  << "empty - " << pq.top();
        
        while(!pq.empty()) {
            ListNode * top = pq.top(); 
            tail->next = new ListNode(top->val);
            pq.pop();
            if (top->next != NULL) {
                pq.push(top->next);
            }
            tail = tail->next;
        }
    
        return dummy_head->next;
    }
};
