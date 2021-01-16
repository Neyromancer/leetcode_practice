struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val( 0 ), next( nullptr ) {}
  ListNode( int x ) : val( x ), next( nullptr ) {}
  ListNode( int x, ListNode *next ) : val( x ), next( next ) {}
};

ListNode *mergeKLists( std::vector<ListNode *> &lists ) {
  if( lists.empty() )
    return nullptr;

  if( lists.size() == 1 )
    return lists.front();

  ListNode *head = lists.front();
  for( int i = 1; i < lists.size(); ++i )
    merge( &head, lists[ i ] );

  return head;
}

void merge( ListNode **l1, ListNode *l2 ) {
  if( !( *l1 ) && l2 ) {
    *l1 = l2;
    return;
  }

  auto node = *l1;
  while( l2 ) {
    if( l2->val <= node->val ) {
      auto tmp = l2;
      l2 = l2->next;
      tmp->next = *l1;
      *l1 = tmp;
      node = *l1;
    } else {
      auto prev = node;
      while( node && l2->val > node->val ) {
        prev = node;
        node = node->next;
      }

      if( !node ) {
        prev->next = l2;
        break;
      }

      auto tmp = l2;
      l2 = l2->next;
      prev->next = tmp;
      tmp->next = node;
      node = *l2;
    }
  }
}
