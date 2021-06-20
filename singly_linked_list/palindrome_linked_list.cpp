class Solution {
public:
    // time O( N ), N == list.size
    // space O( 1 )
    ListNode *reverse( ListNode *head )
    {
        if( !head || !head->next )
            return head;
        
        auto cur = head;
        while( cur && cur->next ) {
            auto tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = head;
            head = tmp;
        }
        
        return head;
    }
    
    bool isPalindrome(ListNode* head)
    {
        if( !head || !head->next )
            return true;
        
        auto s = head;
        auto f = head->next;
        while( s && f && f->next ) {
            s = s->next;
            f = f->next->next;
        }
        
        auto r = reverse( s );
        while( head && r ) {
            if( head->val != r->val )
                return false;
            
            head = head->next;
            r = r->next;
        }
        
        return true;
    }
};
