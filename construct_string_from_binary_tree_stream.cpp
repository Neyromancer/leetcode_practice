#include <stringstream>
#include <string>

std::string tree2str( TreeNode *t ) {
  if( !t )
    return {};

  std::stringstream ss;
  traverse( t, ss );
  return ss.str();
}

void traverse( TreeNode *t, std::stringstream &ss ) {
  if( !t )
    return;

  ss << t->val;
  if( t->right || t->left ) {
    ss << "(";
    traverse( t->left, ss );
    ss << ")";
  }

  if( t->right ) {
    ss << "(";
    traverse( t->right, ss );
    ss << ")";
  }
}
