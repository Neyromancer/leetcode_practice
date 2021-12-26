class Solution {
public:
    int length( ListNode* head )
    {
        int cnt{ 0 };
        auto cur = head;
        while( cur ) {
            ++cnt;
            cur = cur->next;
        }
        return cnt;
    }
    // time O( N )
    // space O( 1 )
    ListNode* rotateRight(ListNode* head, int k)
    {
        if( !head || !head->next )
            return head;

        int len = length( head );
        k = k % len;
        if( !k )
            return head;

        auto right = head;
        while( k-- >= 0 )
            right = right->next;

        auto left = head;
        while( right ) {
            left = left->next;
            right = right->next;
        }

        if( !left )
            return head;
        
        auto node = left->next;
        auto cur = node;
        while( cur && cur->next )
            cur = cur->next;
        left->next = nullptr;
        cur->next = head;
        return node;
    }
};
