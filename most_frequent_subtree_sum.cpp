#include <unordered_map>
#include <vector>

class Solution {
  std::unordered_map<int, int> st;

public:
  std::vector<int> findFrequentTreeSum( TreeNode *root ) {
    if( root == nullptr )
      return {};

    ( void )calc_sum_freq( root );
    
    int max_freq{ 0 };
    for( auto[ el , freq ] : st )
      max_freq = std::max( max_freq, freq );

    std::vector<int> res;
    for( auto[ el, freq ] : st ) {
      if( freq == max_freq )
        res.push_back( el );
    }

    return res;
  }

  int calc_sum_freq( TreeNode *root ) {
    if( !root )
      return 0;

    auto tmp = root->val + calc_sum_freq( root->left ) + calc_sum_freq( root->right );
    ++st[ tmp ];
    return tmp;
  }
};

