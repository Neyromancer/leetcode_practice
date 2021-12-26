class Solution {
public:
    // time O( N )
    // space O( 1 )
    ListNode* partition(ListNode* head, int x)
    {
        if( !head || !head->next )
            return head;

        ListNode* smaller_nodes = new ListNode();
        ListNode* prev_smaller = nullptr;
        ListNode* greater_nodes = new ListNode();
        ListNode* prev_greater = nullptr;
        auto cur = head;
        while( cur ) {
            if( cur->val < x ) {
                if( !prev_smaller ) {
                    smaller_nodes->next = cur;
                    prev_smaller = smaller_nodes;
                } else {
                    prev_smaller->next = cur;
                }
                prev_smaller = prev_smaller->next;
            } else {
                if( !prev_greater ) {
                    greater_nodes->next = cur;
                    prev_greater = greater_nodes;                   
                } else {
                    prev_greater->next = cur;
                }
                prev_greater = prev_greater->next;                
            }
            cur = cur->next;
        }

        if( prev_greater )
            prev_greater->next = nullptr;
        if( prev_smaller )
            prev_smaller->next = greater_nodes->next;
        return smaller_nodes->next ? smaller_nodes->next : greater_nodes->next;
    }
};
