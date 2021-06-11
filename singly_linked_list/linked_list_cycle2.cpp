class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        auto s = head;
        auto f = head;
        while( f && f->next ) {
            f = f->next->next;
            s = s->next;

            if( s == f ) {
                s = head;
                while( s != f ) {
                    s = s->next;
                    f = f->next;
                }
                
                return s;
            }
        }
        
        return nullptr;
    }
};
