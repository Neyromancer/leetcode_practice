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
