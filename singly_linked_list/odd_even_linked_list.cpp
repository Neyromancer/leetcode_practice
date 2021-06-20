class Solution {
public:
    // time O( 1 )
    // space O( N ), where N == list.size
    ListNode* oddEvenList(ListNode* head)
    {
        if( !head || !head->next )
            return head;
        
        auto odd = head;
        auto even = head->next;
        ListNode *even_head = even;
        while( even && even->next ) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        
        return head;
    }
};
