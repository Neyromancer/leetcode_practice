// time O( N ), N - size of list
// space O( 1 )
ListNode* deleteDuplicates(ListNode* head) {
    if( !head || !head->next )
        return head;
        
    if( head->val == head->next->val ) {
        auto value = head->val;
        while( head && value == head->val )
            head = head->next;
            
        if( !head || !head->next )
            return head;
    }
        
    ListNode *prev = nullptr;
    ListNode *current = head;
    while( current ) {
        if( current->next && current->val == current->next->val ) {
            int value = current->val;
            while( current && value == current->val )
                current = current->next;
                
            if( !prev ) {
                head = current;
            } else {
                prev->next = current;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
        
    return head;
}
