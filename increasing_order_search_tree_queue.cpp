#include <queue>

TreeNode increasingBST( TreeNode *root ) {
  if( !root )
    return root; 

  std::queue<TreeNode *> storage;
  traverse( root, storage );
  TreeNode *result = storage.front();
  storage.pop();
  TreeNode *p = result;
  while( !storage.empty() ) {
    auto node = storage.front();
    storage.pop();
    if( node ) {
      p->right = node;
      p->left = nullptr;
      p = p->right;
    }
  }

  p->right = nullptr;
  p->left = nullptr;

  return result;
}

void traverse( TreeNode *root, std::queue<TreeNode *> &storage ) {
  if( !root )
    return nullptr;

  traverse( root->left, storage );
  storage.push( root );
  traverse( root->right, storage );
}
