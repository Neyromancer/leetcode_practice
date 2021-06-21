// time O( N ), where N == sizeof( l1 || l2 )
// space O( 1 )
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if( !l1 && !l2 )
            return nullptr;
        
        if( !l1 || !l2 )
            return l1 ? l1 : l2;
        
        if( l1->val > l2->val ) {
            auto tmp = l2;
            l2 = l1;
            l1 = tmp;
        }
        
        
        auto cur1 = l1;
        auto cur2 = l2;
        while( cur1 && cur2 ) {
            if( cur1 && cur2 && cur1->val > cur2->val ) {
                auto tmp = cur2;
                cur2 = cur1;
                cur1 = tmp;                
            }
            
            ListNode *prev = nullptr;
            while( cur1 && cur2 && cur1->val <= cur2->val ) {
                prev = cur1;
                cur1 = cur1->next;
            }
            
            if( prev ) {
                auto tmp = cur2->next;
                prev->next = cur2;
                cur2->next = cur1;
                cur2 = tmp;
                cur1 = prev;
            }
        }
        
        return l1;
    }
};
