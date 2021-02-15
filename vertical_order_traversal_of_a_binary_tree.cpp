#include <algorithm>
#include <map>
#include <vector>


std::vector<std::vector<int>> verticalTraversal( TreeNode *root ) {
  if( !root )
    return {};

  std::map<int, std::vector<std::pair<int, int>>, std::less<int>> storage;
  traverse( root, storage, 0, 0 );
  
  std::vector<std::vector<int>> res;
  for( auto &&[ key, val ] : storage ) {
    std::sort( std::begin( val ), std::end( val ), []( const auto &el1,
                                                       const auto &el2 ) {
      return ( ( el1.first > el2.first ) || ( el1.first == el2.first && el1.second < el2.second ) );
    } );

    std::vector<int> tmp;
    std::for_each( std::begin( val ), std::end( val ), [ &tmp ]( const auto &el ) {
      tmp.push_back( el.second );
    } );

    res.push_back( std::move( tmp ) );
  }

  return res;
}

void traverse( TreeNode *root, std::map<int, std::vector<std::pair<int, int>>, std::less<int>> &st, 
               int x, int lvl ) {
  if( !root )
    return;

  auto &vc = st[ x ];
  vc.push_back( std::make_pair( lvl, root->val ) );
  traverse( root->left, st, x - 1, lvl + 1 );
  traverse( root->right, st, x + 1, lvl + 1 );
}
