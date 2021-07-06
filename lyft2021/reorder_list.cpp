class Solution {
public:
    
     // time O( N ), N == sizeof( list )
    // space O( 1 )
    void reorderList(ListNode* head)
    {
        if( !head || !head->next )
            return;
        
        ListNode *pslow = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        // time O( N ), N == sizeof( list )
        while( fast && fast->next ) {
            pslow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        pslow->next = nullptr;
         // time O( N ), N == sizeof( list )
        auto end = reverse( slow );
        auto cur = head;
         // time O( N ), N == sizeof( list )
        while( cur->next ) {
            auto cnext = cur->next;
            auto enext = end->next;
            
            cur->next = end;
            end->next = cnext;
            if( !cnext && enext ) {
                end->next = enext;
            }
            cur = cnext;
            end = enext;
        }
	cur->next = end;
    }
    
    ListNode *reverse( ListNode *head )
    {
        if( !head || !head->next )
            return head;
        
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while( cur ) {
            auto nnode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nnode;
        }
        
        return prev;
    }
};
