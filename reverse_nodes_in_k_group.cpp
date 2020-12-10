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

ListNode *reverseKGroup( ListNode *head, int k ) {
  if( !head || !head->next || k == 1 )
    return head;

  auto l = length( head );
  ListNode *cur = head;
  ListNode *start = new ListNode();
  ListNode *tmp_start = start;
  while( l >= k ) {
    l -= k;
    tmp_start->next = reverse( &cur, k );
    
    while( tmp_start->next )
      tmp_start = tmp_start->next;
  }

  tmp_start->next = cur;
  return start->next;
}

int length( ListNode *head ) {
  if( !head )
    return 0;

  int l{ 0 };
  ListNode *node = head;
  while( node ) {
    node = node->next;
    ++l;
  }

  return l;
}

ListNode *reverse( ListNode **head, int k ) {
  if( !*head )
    return *head;


  ListNode *cur = *head;
  ListNode *prev = nullptr;
  while( cur && k-- > 0 ) {
    auto tmp = cur->next;
    cur->next = prev;
    prev = cur;
    cur = tmp;
  }

  *head = cur;
  return prev;
}
