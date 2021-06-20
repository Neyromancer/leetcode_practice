class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if( !headA || !headB )
            return nullptr;
        
        auto nodeA = headA;
        auto nodeB = headB;
        while( nodeA != nodeB ) {
            nodeA = !nodeA ? headB : nodeA->next;
            nodeB = !nodeB ? headA : nodeB->next;
        }
        
        return nodeA;
    }
};
