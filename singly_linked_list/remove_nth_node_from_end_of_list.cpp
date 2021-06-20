class Solution {
public:
    // time O( N ), where N == lists.size()
    // space O( 1 )
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        auto last = head;
        auto cur = head;
        ListNode *prev = nullptr;
        while( last && last->next ) {
            last = last->next;
            if( --n <= 0 ) {
                prev = cur;
                cur = cur->next;
            }
        }
        
        if( !prev ) {
            head = head->next;
            return head;
        }
        
        prev->next = cur->next;
        return head;
    }
};
