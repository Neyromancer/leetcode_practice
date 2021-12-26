// iterative approach
class Solution {
public:
    // time O( N )
    // space O( 1 )
    ListNode* swapPairs(ListNode* head)
    {
        if( !head || !head->next )
            return head;

        ListNode* dummy = new ListNode();
        dummy->next = head;
        auto prev_node = dummy;
        auto cur_node = head;
        auto next_node = head->next;

        while( next_node ) {
            auto tmp = next_node ? next_node->next : nullptr;
            cur_node->next = tmp;
            next_node->next = cur_node;
            prev_node->next = next_node;
            prev_node = cur_node;
            cur_node = tmp;
            next_node = cur_node ? cur_node->next : nullptr;
        }
        
        return dummy->next;
    }
};

// recursive approach
ass Solution {
public:
    // time O( N )
    // space O( N )
    ListNode* swapPairs(ListNode* head)
    {
        if( !head || !head->next )
            return head;

        auto first_node = head;
        auto second_node = head->next;
        first_node->next = swapPairs( second_node->next );
        second_node->next = first_node;
        
        return second_node;
    }
};
