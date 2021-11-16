class Solution {
    int max_path{ 0 };
public:
    // time O( N ), where N is the number of nodes
    // space O( H ), where H is the height of the tree
    int diameterOfBinaryTree(TreeNode* root) {
        dfs( root );
        return max_path;
    }
    
    int dfs( TreeNode* root ) {
        if( !root )
            return 0;
        
        auto l = dfs( root->left );
        auto r = dfs( root->right );
        max_path = std::max( max_path, l + r );
        return std::max( l, r ) + 1;
    }
};


