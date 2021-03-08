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

// space O( 1 )
// time O( N ), N - size of the longest list
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        b -= a;
        ListNode *prev = nullptr;
        ListNode *current = list1;
        while( a-- > 0 && current ) {
            prev = current;
            current = current->next;
        }
        
        if( prev )
            prev->next = nullptr;
        
        ListNode *future = current->next;
        while( b-- > 0 && future ) {
            current = future;
            future = future->next;
        }
        
        if( current )
            current->next = nullptr;
        
        if( prev )
            prev->next = list2;
        while( list2 && list2->next )
            list2 = list2->next;
        
        list2->next = future;
        
        return list1;
    }
};
////////////////////////////////////////////////////////////////////////////////
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    int cnt{ 0 };
    ListNode *prev = list1;
    while( ++cnt != a )
      prev = prev->next;
        
    ListNode *current = prev->next;
    prev->next = list2;
    while( a++ != b )
      current = current->next;
        
    while( prev && prev->next )
      prev = prev->next;
        
    prev->next = current->next;
    return list1;
}

///////////////////////////////////////////////////////////////////////////////
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    auto current = list1;
    for( int i = 0; i < a - 1; ++i )
        current = current->next;
        
    auto future = list1;
    for( int i = 0; i < b; ++i )
        future = future->next;
        
    current->next = list2;
    while( current && current->next )
        current = current->next;
        
    current->next = future->next;
    return list1;
}
