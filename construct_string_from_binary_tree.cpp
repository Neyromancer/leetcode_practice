#include <string>

std::string tree2str( TreeNode *t ) {
  if( !t )
    return {};

  std::string l{ "(" };
  if( t->left )
    l += tree2str( t->left );
  l += ")";

  std::string r;
  if( t->right )
   r = "(" + tree2str( t->right ) + ")";

  if( !t->left && !t->right )
    return std::to_string( t->val );

  return std::to_string( t->val ) + l + r;
}
