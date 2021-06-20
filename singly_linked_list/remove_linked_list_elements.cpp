class Solution {
public:
    // space O( 1 )
    // time O( N ), where N == list.size()
    ListNode* removeElements(ListNode* head, int val)
    {
        if( !head )
            return head;
        
        while( head && head->val == val )
            head = head->next;
        
        if( !head || !head->next )
            return head;
        
        auto cur = head;
        ListNode *prev = nullptr;
        while( cur ) {
            if( cur->val == val )
                prev->next = cur->next;
            else
                prev = cur;
            
            cur = cur->next;
        }
        
        return head;
    }
};
