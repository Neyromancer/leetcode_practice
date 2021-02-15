#include <vector>

ListNode *mergeKLists( std::vector<ListNode*> &lists ) {
  if( lists.empty() )
    return nullptr;

  if( lists.size() == 1 )
    return lists.front();

  auto res = lists.front();
  for( int i = 1; i < lists.size(); ++i )
    res = merge_lists( res, lists[ i ] );

  return res;
}

ListNode *merge_lists( ListNode *l1, ListNode *l2 ) {
  if( !l1 || !l2 )
    return ( l2 ) ? l2 : l1;

  if( l1->val >= l2->val ) {
    auto head = l2;
    auto prev = l2;
    while( l2 && l2->val <= l1->val ) {
      prev = l2;
      l2 = l2->next;
    }

    prev->next = l1;
    l1 = head;
    if( !l2 )
      return l1;
  }

  auto n1 = l1;
  while( n1 && l2 ) {
    auto prev = n1;
    while( n1 && n1->val <= l2->val ) {
      prev = n1;
      n1 = n1->next;
    }

    if( prev != n1 ) {
      prev->next = l2;
      l2 = l2->next;
      prev = prev->next;
      prev->next = n1;
      n1 = prev;
      continue;
    }

    if( n1 )
      n1 = n1->next;
  }

  return l1;
}
