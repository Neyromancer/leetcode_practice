#include <vector>
#include <priority_queue>

class Solution {
  struct cmp {
    bool operator() ( ListNode *left, ListNode *right ) {
      if( !left )
        return false;

      if( !right )
        return true;

      return left->val > right->val;
    }
  };

public:
  ListNode *mergeKLists( std::vector<ListNode *> &lists ) {
    if( lists.empty() )
      return nullptr;

    if( lists.size() == 1 )
      return lists.front();

    std::priority_queue<ListNode *, std::vector<ListNode *>, cmp> q;
    for( auto &&l : lists ) {
      if( l )
        q.push( std::move( l ) );

      ListNode *dummy = new ListNode();
      ListNode *cur = dummy;
      while( !q.empty() ) {
        ListNode *minNode = q.top();
        q.pop();
        if( minNode->next )
          q.push( minNode->next );
        cur->next = minNode;
        cur = cur->next;
      }

      ListNode *tmp = dummy->next;
      delete dummy;
      return tmp;
    }
  }
};
