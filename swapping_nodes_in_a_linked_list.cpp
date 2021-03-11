// time O( N ), where N - size of the list
// space O( N ), where N - size of the list
class Solution {
    int cnt{ 1 };
    ListNode *forward = nullptr;
    ListNode *backward = nullptr;
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if( !head ) {
            cnt = 0;
            return head;
        }
        
        if( cnt == k ) {
            if( !forward )
                forward = head;
        }
        ++cnt;
        
        auto node = swapNodes( head->next, k );
        
        ++cnt;
        if( cnt == k ) {
            if( !backward )
                backward = head;
            
            if( backward && forward )
                std::swap( backward->val, forward->val );
        }
        
        return head;
    }
};

// space O( 1 )
// time O( N )
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k)
    {
        if( !head )
            return head;
        
        auto current = head;
        ListNode *begin = nullptr;
        int cnt{ 1 };
        while( cnt <= k ) {
            begin = current;
            current = current->next;
            ++cnt;
        }
        
        auto back = head;
        current = begin;
        while( current->next ) {
            back = back->next;
            current = current->next;
        }
        
        std::swap( begin->val, back->val );
        return head;
    }
};
