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


///////////////////////////////////////////////////////////////
// time O( N * M ), where N - size of the lists ( vector ) and M size of longest ( final ) list 
// space O( N ), where N size of lists ( vector )
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if( lists.empty() || ( lists.size() == 1 && !lists.front() ) )
            return nullptr;
        
        return helper( lists, 0, lists.size() - 1 );
    }
    
    ListNode *helper( const std::vector<ListNode *> &lists, int start, int end )
    {
        if( start == end )
            return lists[ start ];
        
        int mid = start + ( end - start ) / 2;
        auto left = helper( lists, start, mid );
        auto right = helper( lists, mid + 1, end );
        return merge( left, right );
    }
    
    ListNode *merge( ListNode* &l1, ListNode* l2 )
    {
        if( !l1 )
            return l2;
        
        if( !l2 )
            return l1;
        
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        while( l1 && l2 ) {
            if( l1->val < l2->val ) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            
            cur = cur->next;
        }
        
        if( l1 || l2 )
            cur->next = ( l1 ) ? l1 : l2;

        return dummy->next;
    }
};

// space O( N x M ), where N - vector size and M longest list size
// time O( N x M ), where N - vector size and M longest list size
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if( lists.empty() || ( lists.size() == 1 && !lists.front() ) )
            return nullptr;
        
        auto comp = []( const ListNode *l1,
                        const ListNode *l2 ) {
            if( !l1 )
                return true;
            
            if( l1 && !l2 )
                return false;
            
            if( !l1 && !l2 )
                return true;
            
            return l1->val >= l2->val;
        };
        
        std::priority_queue<ListNode *, std::vector<ListNode *>, decltype( comp )> queue( comp );
        for( auto &l : lists ) {
            if( !l )
                continue;
            
            queue.push( l );
        }
        
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        
        while( !queue.empty() ) {
            cur->next = queue.top();
            queue.pop();
            cur = cur->next;
            
            if( cur->next )
                queue.push( cur->next );
        }
        
        return dummy->next;
    }
};

// space O( N x M ), where N - vector size and M longest list size
// time O( N x M ), where N - vector size and M longest list size
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if( lists.empty() || ( lists.size() == 1 && !lists.front() ) )
            return nullptr;
        
        return partition( lists, 0, lists.size() - 1 );
    }
    
    ListNode *partition( const vector<ListNode*>& lists, int start, int end )
    {
        if( start == end )
            return lists[ start ];
        
        int mid = start + ( end - start ) / 2;
        auto left = partition( lists, start, mid );
        auto right = partition( lists, mid + 1, end );
        
        return merge( left, right );
    }
    
    ListNode *merge( ListNode *l1, ListNode *l2 )
    {
        if( !l1 )
            return l2;
        
        if( !l2 )
            return l1;
        
        if( l1->val < l2->val ) {
            l1->next = merge( l1->next, l2 );
            return l1;
        }
        
        l2->next = merge( l1, l2->next );
        return l2;
    }
};
