// time complexity O( N ), N - number of nodes in the tree
// space complexity O( H ), H - height of the tree 
TreeNode *pruneTree( TreeNode *root ) {
  if( !root )
    return nullptr;

  return traverse( root ) ? root : nullptr;
}

bool traverse( TreeNode *root ) {
  if( !root )
    return false;

  auto l = traverse( root->left );
  if( !l )
    root->left = nullptr;

  if( !r )
    root->right = nullptr;

  return ( root->val == 1) || l || r;
}
