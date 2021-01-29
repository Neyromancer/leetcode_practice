#include <algorithm>
#include <map>
#include <queue>
#include <vector>

std::vector<std::vector<int>> verticalTraversal( TreeNode *root ) {
  if( !root )
    return {};

  std::map<int, std::vector<int>> st;
  std::queue<std::pair<int, TreeNode *>> q;
  q.push( { 0, root } );
  while( !q.empty() ) {
    int sz = q.size();
    std::map<int, std::vector<int>> tmp;
    while( sz-- > 0 ) {
      auto node = q.front();
      q.pop();

      tmp[ node.first ].push_back( node.second->val );
      if( node.second->left )
        q.push( { node.first - 1, node.second->left } );

      if( node.second->right )
        q.push( { node.first + 1, node.second->right } );
    }

    for( auto &&[ key, vc ] : tmp ) {
      std::sort( std::begin( vc ), std::end( vc ) );
      auto &val = st[ key ];
      val.insert( std::end( val ), std::begin( vc ), std::end( vc ) );
    }
  }

  std::vector<std::vector<int>> res;
  for( auto &&[ k, v ] : st )
    res.push_back( std::move( v ) );

  return res;
}
