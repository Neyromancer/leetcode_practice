// time complexity O( N ) - list length
// space complexity O( N ) - list length
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if( !head )
            return head;
        
        if( n == 1 && !head->next )
            return nullptr;

        return removeNthNodeFromEnd( head, n, head );
    }
    
    ListNode *removeNthNodeFromEnd( ListNode *node, int &n, ListNode *head )
    {
        if( !node->next )
            return node;
        
        ListNode *future = removeNthNodeFromEnd( node->next, n, head );
        if( n >= 0 )
            --n;
        
        if( n == 0 ) {
            node->next = future->next;
            return node;
        }
        
        if( n == 1 && head == node ) {
            head = head->next;
            return head;
        }
        
        if( n < 0 )
            return node;
        
        if( node && node->next )
            return node;
        
        return nullptr;
    }
};

//////////////////////////////////////////////////////////////
ListNode* removeNthFromEnd( ListNode* head, int n ) {
    ListNode *dummy = new ListNode( -1 );
    dummy->next = head;
    ListNode *first = dummy;
    ListNode *second = dummy;
    for( int i = 1; i <= n + 1; ++i )
        first = first->next;
        
    while( first ) {
        second = second->next;
        first = first->next;
    }

    second->next = second->next->next;
    return dummy->next;
}
