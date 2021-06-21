class Solution {
public:
    // time O( N ), where N == sizeof( l1 || l2 )
    // space O( 1 )
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if( !l1 && !l2 )
            return nullptr;
        
        if( !l1 || !l2 )
            return ( l1 ? l1 : l2 );
        
        int aux{ 0 };
        auto c1 = l1;
        auto c2 = l2;
        while( c1 || c2 ) {
            ListNode *prev = nullptr;
            while( c1 && c2 ) {
                auto tmp = c1->val + c2->val + aux;
                aux = tmp / 10;
                c1->val = tmp % 10;
                prev = c1;
               if( !c1->next && aux ) {
                    c1->next = new ListNode( aux );
                    aux = 0;
                }                
                c1 = c1->next;
                c2 = c2->next;
            }
 
            if( c1 && !c2 ) {
                auto tmp = c1->val + aux;
                aux = tmp / 10;
                c1->val = tmp % 10;
                if( !c1->next && aux ) {
                    c1->next = new ListNode( aux );
                    aux = 0;
                }
                c1 = c1->next;
            } else if( !c1 && c2 ) {
                prev->next = c2;
                c1 = prev;
                c1 = c1->next;
                c2 = nullptr;
            }
        }
        
        return l1;
    }
};
