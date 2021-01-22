#include <unordered_map>


class FindElements {
  TreeNode *tree{ nullptr };
  std::unordered_map<int, int> st;

public:
  FindElements( TreeNode *root ) {
    root->val = 0;
    recover( root );
    tree = root;
  }

  bool find( int target ) {
    return st[ target ];
  }

  void recover( TreeNode *root ) {
    if( !root )
      return;

    st[ root->val ] = 1;
    if( root->left )
      root->left->val = 2 * root->val + 1;

    if( root->right )
      root->right->val = 2 * root->val + 2;

    recover( root->left );
    recover( root->right );
  }

};
