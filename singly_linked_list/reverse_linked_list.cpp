// iterative approach
class Solution {
public:
    // space O( 1 )
    // time O( N ), where N == list.size()
    ListNode* reverseList(ListNode* head)
    {
        if( !head || !head->next )
            return head;
        
        auto cur = head;
        while( cur->next ) {
            auto tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = head;
            head = tmp;
        }
        
        return head;
    }
};

// recursive solution
class Solution {
public:
    ListNode *reverseList( ListNode *head, ListNode *prev )
    {
        if( !head )
            return prev;
        
        auto node = head->next;
        head->next = prev;
        return reverseList( node, head );
    }
    
    ListNode* reverseList(ListNode* head)
    {
        return reverseList( head, nullptr );
    }
};
