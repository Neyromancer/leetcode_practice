#include <stack>

void flatten( TreeNode *root ) {
  if( !root )
    return;

  std::stack<TreeNode *> storage;
  auto head = root;
  storage.push( head );
  while( !storage.empty() ) {
    auto node = storage.top();
    storage.pop();
    if( node->right )
      storage.push( node->right );

    if( node->left )
      storage.push( node->left );

    if( node == root )
      continue;

    head->right = node;
    head->left = nullptr;
    head = head->right;
  }
}
