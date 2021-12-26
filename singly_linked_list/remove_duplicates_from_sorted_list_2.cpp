class Solution {
public:
    // time O( N )
    // space O( 1 )
    ListNode* deleteDuplicates( ListNode* head )
    {
        if( !head || !head->next )
            return head;
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        auto prev_node = dummy;
        auto cur_node = head;
        auto next_node = head->next;
        while( next_node ) {
            if( next_node && cur_node->val == next_node->val ) {
                while( next_node && cur_node->val == next_node->val ) {
                    next_node = next_node->next;
                }

                cur_node = next_node;
                prev_node->next = cur_node;
                next_node = next_node ? next_node->next : nullptr;
                continue;
            }

            prev_node = cur_node;
            cur_node = cur_node->next;
            next_node = next_node->next;    
        }
        
        return dummy->next;
    }
};
