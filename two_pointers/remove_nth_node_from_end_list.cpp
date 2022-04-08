class Solution {
public:
    // TC: O( sizeof( head ) )
    // SC: O( 1 )
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if ( !head )
            return head;

        auto last_node = head;
        while( n-- > 0 )
            last_node = last_node->next;
        
        ListNode* cur_node = head;
        ListNode* prev_node = nullptr;
        while( last_node ) {
            prev_node = cur_node;
            cur_node = cur_node->next;
            last_node = last_node->next;
        }
        
        if ( !prev_node ) {
            head = head->next;
            return head;
        }
        
        prev_node->next = cur_node->next;
        return head;
    }
};
