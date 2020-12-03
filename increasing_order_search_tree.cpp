TreeNode increasingBST( TreeNode *root ) {
  if( !root )
    return nullptr;

  auto lnode = increasingBST( root->left );
  root->right = increasingBST( root->right );
  
  TreeNode *node = lnode;
  while( node && node->right )
    node = node->right;

  if( node )
    node->right = root;

  root->left = nullptr;

  return ( lnode ) ? lnode : root;
}
