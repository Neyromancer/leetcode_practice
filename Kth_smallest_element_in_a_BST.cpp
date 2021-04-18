class Solution {
public:
    // time O( N ), where N is the number of nodes
    // space O( N ), where N is the number of nodes
    int kthSmallest(TreeNode* root, int k)
    {
        if( !root )
            return 0;
        
        return traverse( root, k );
    }
    
    int traverse( TreeNode *root, int &k )
    {
        if( !root )
            return 0;
        
        auto l = traverse( root->left, k );
        int res{ 0 };
        if( --k == 0 )
            res = root->val;
        
        auto r = traverse( root->right, k );
        
        return max( l, res, r );
    }
    
    int max( int n1, int n2, int n3 )
    {
        int res = std::max( n1, n2 );
        res = std::max( res, n3 );
        return res;
    }
};
