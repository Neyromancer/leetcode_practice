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
    /**
    [3,4,5,1,2]
[4,1,2]
[1,1]
[1]
[3,4,5,1,2,null,null,0]
[4,1,2]
 [1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,2]
[1,null,1,null,1,null,1,null,1,null,1,2]   
    */
public:
    // space O( S.size() ), number of node
    // time O( S.size() ), we have to walk through the whole tree
    bool isSubtree(TreeNode* s, TreeNode* t)
    {
        std::vector<TreeNode *> st;
        walk( s, st, t );
        for( const auto &node : st )
            if( compare( node, t ) )
                return true;
            
        return false;
    }
    
    void walk( TreeNode *s, std::vector<TreeNode *> &st, TreeNode *t )
    {
        if( !s )
            return;
        
        if( s->val == t->val )
            st.push_back( s );
        
        walk( s->left, st, t );
        walk( s->right, st, t );
    }
    
    bool compare( TreeNode *node, TreeNode *t )
    {
        if( !node && !t )
            return true;
        
        if( !node || !t )
            return false;
        
        if( node->val == t->val )
            return compare( node->left, t->left ) && compare( node->right, t->right );

        return false;
    }
};
