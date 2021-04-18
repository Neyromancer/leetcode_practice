/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root)
    {
        if( !root )
            return 0;

        int res{ INT_MIN };
        (void)walk_through_path( root, res );
        return res;
    }
    
    int walk_through_path( TreeNode *root, int &res )
    {
        if( !root )
            return 0;

        auto l = std::max( 0, walk_through_path( root->left, res ) );
        auto r = std::max( 0, walk_through_path( root->right, res ) );
        res = std::max( res, l + r + root->val );
        return std::max( l, r ) + root->val;
    }
};
