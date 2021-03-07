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

bool isPalindrome( ListNode *head ) {
  if( !head || head->next == nullptr )
    return true;

  auto mid = get_mid( head );
  auto rev = reverse( mid );
  while( head && rev ) {
    if( head->val != rev->val )
      return false;
  }

  return true;
}

ListNode *get_mid( ListNode *head ) {
  if( head->next->next == nullptr )
    return head->next;

  ListNode *s = head;
  ListNode *f = head->next->next;
  while( f && f->next ) {
    s = s->next;
    f = f->next->next;
  }
  return s->next;
}

ListNode *reverse( ListNode *head ) {
  ListNode *prev = nullptr;
  ListNode *cur = head;
  while( cur ) {
    auto tmp = cur->next;
    cur->next = prev;
    prev = cur;
    cur = tmp;
  }

  return prev;
}

////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isPalindrome(ListNode* head)
    {
        ListNode *back = nullptr;
        bool is_end{ false };
        if( is_palindrome( head, is_end, back, head ) )
            return true;
        
        return false;
    }
    
    bool is_palindrome( ListNode *cur, bool &end, ListNode * &back, ListNode *head )
    {
        if( !cur ) {
            end = true;
            return true;
        }
        
        bool is_end = false;
        ListNode *end_node = nullptr;
        auto eq = is_palindrome( cur->next, is_end, end_node, head );
        if( !eq )
            return false;
        
        if( is_end ) {
            back = head;
        } else {
            back = end_node->next;
        }
        
        if( cur->val == back->val )
            return true;
        
        return false;
    }
};
