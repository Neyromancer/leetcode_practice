/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

#include <queue>
// Space O( N )
// Time O( N )
Node *connect( Node *root ) {
  if( !root )
    return nullptr;

  std::queue<Node *> storage;
  storage.push( root );
  int sz{ 1 };
  while( !storage.empty() ) {
    int tmp_sz{ 0 };
    for( int i = 0; i < sz; ++i ) {
      auto node = storage.front();
      storage.pop();
      if( i < sz - 1 ) {
        node->next = storage.front();
      } else {
        node->next = nullptr;
      }

      if( node->left ) {
        ++tmp_sz;
        storage.push( node->left );
      }

      if( node->right ) {
        ++tmp_sz;
        storage.push( node->right );
      }
    }

    sz = tmp_sz;
  }

  return root;
}
