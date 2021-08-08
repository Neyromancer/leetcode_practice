[1,2,3]
[-10,9,20,null,null,15,7]
[-10,9,20,null,21,15,7,null,-10,null,null,null,1,null,5,11,null,-19]
[1]
[1,2]
[2,-1]
[-10,100]
[1,-2,3]
*/
class Solution {
    int m_mpath{ std::numeric_limits<int>::min() };
public:
    int maxPathSum(TreeNode* root)
    {
        if( !root )
            return 0;
        
        find_path( root );
        return m_mpath;
    }
    
    int find_path( TreeNode *root )
    {
        if( !root )
            return 0;
        
        auto l = std::max( find_path( root->left ), 0 );
        auto r = std::max( find_path( root->right ), 0 );
        
        m_mpath = std::max( m_mpath, root->val + l + r );
        return root->val + std::max( l, r );
    }
};
