/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// space O( N ), where N - size of the list
// time O( N ), where N - size of the list
class Solution {
public:
    ListNode *reverse_list( ListNode *head, ListNode *prev ) {
        if( !head )
            return prev;
        
        auto tmp = head->next;
        head->next = prev;
        return reverse_list( tmp, head );
    }
    
    ListNode *reverse( ListNode *head ) {
        ListNode *prev = nullptr;
        return reverse_list( head, prev );
    }

    ListNode* reverseBetween( ListNode* head, int left, int right )
    {
        right -= left; // right = 2
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while( --left > 0 ) { // 2 1 0
            prev = cur; // 1
            cur = cur->next; // 2
        }
        
        while( --right >= 0 )
            cur = cur->next;
        
        ListNode *tmp = ( !prev ) ? head : prev->next;
        ListNode *future = cur->next;
        cur->next = nullptr;
        auto node = reverse( tmp );
        
        if( prev )
            prev->next = node;
        else
            head = node;

        while( node && node->next )
            node = node->next;
        
        node->next = future;
        
        return head;
    }
};
