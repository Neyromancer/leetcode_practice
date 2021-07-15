class Solution {
public:
    // time O( N ), N == sizeof( list )
    // space O( 1 )
    ListNode* reverseList(ListNode* head)
    {
        if( !head )
            return head;
        
        auto cur = head;
        ListNode *prev = nullptr;
        while( cur ) {
            auto tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        
        return prev;
    }
};
