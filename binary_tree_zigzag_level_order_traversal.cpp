#include <vector>
#include <queue>

std::vector<std::vector<int>> zigzagLevelOrder( TreeNode *root ) {
  if( !root )
    return {};

  std::vector<std::vector<int>> res;
  std::queue<TreeNode *> storage;
  storage.push( root );
  while( !storage.empty() ) {
    auto sz = storage.size();
    storage.pop();
    tmp.push_back( node->val );

    if( node->left )
      storage.push( node->left );

    if( node->right )
      storage.push( node->right );
  }

  for( int i = 0; i < res.size(); ++i )
    if( ( i + 1 ) % 2 == 0 )
      std::reverse( std::begin( res[ i ] ), std::end( res[ i ] ) );

  return res;
}
