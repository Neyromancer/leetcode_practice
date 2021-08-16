class Solution {
    bool ans{ true };
public:
    int count_depth( TreeNode *root )
    {
        if( !root )
            return 0;
        auto l = count_depth( root->left ) + 1;
        auto r = count_depth( root->right ) + 1;
        if( std::abs( l - r ) > 1 )
            ans = false;

        return std::max( l, r );
    }

    // time O( N ), where N is the number of nodes in the tree
    // space O( N ), where N is the number of nodes in the tree
    bool isBalanced( TreeNode* root )
    {
        if( !root )
            return true;
        
        if( !root->left && !root->right )
            return true;
        
        count_depth( root );
        return ans;
    }
};

class Solution {
public:
    int count_depth( TreeNode *root )
    {
        if( !root )
            return 0;
        
        return std::max( count_depth( root->left ), count_depth( root->right ) ) + 1;
    }
    // O( N^2 ), where N is the number of nodes in the tree
    bool isBalanced( TreeNode* root )
    {
        if( !root )
            return true;
        
        if( !root->left && !root->right )
            return true;
        
        auto l = count_depth( root->left ) + 1;
        auto r = count_depth( root->right ) + 1;
        
        return isBalanced( root->left ) && isBalanced( root->right ) && ( std::abs( l - r ) <= 1 );
    }
};
