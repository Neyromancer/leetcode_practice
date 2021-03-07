/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// space O( 1 )
// time O( N ), where N - number of nodes in the linked list
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if( !head )
            return false;
        
        auto slow = head;
        auto fast = head->next;
        while( fast && fast->next ) {
            if( slow == fast )
                return true;
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return false;
    }
};
