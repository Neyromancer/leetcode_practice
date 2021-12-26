class Solution {
public:
    // time O( N )
    // space O( 1 )
    ListNode* reverse( ListNode* head, ListNode* right_border )
    {
        auto cur = head;
        ListNode* prev = nullptr;
        while( cur && cur != right_border ) {
            auto tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }

        return prev;
    }
    
    // time O( N )
    // space O( 1 )
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if( left == right || !head || !head->next )
            return head;
        
        auto left_border = head;
        ListNode* prev = nullptr;
        while( --left > 0 ) {
            prev = left_border;
            left_border = left_border->next;
        }
        
        auto right_border = head;
        while( right-- > 0 )
            right_border = right_border->next;
        
        auto reversed_node = reverse( left_border, right_border );

        auto cur = reversed_node;
        while( cur && cur->next )
            cur = cur->next;
        cur->next = right_border;

        if( prev )
            prev->next = reversed_node;
        else
            head = reversed_node;
        return head;
    }
};
