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
    // time O( all nodes of the tree 0
    // space O( tree height )
    int goodNodes(TreeNode* root)
    {
        if( !root )
            return 0;
        return count_good_nodes( root, INT_MIN );
    }
    
    int count_good_nodes( TreeNode *root, int val )
    {
        if( !root )
            return 0;
        return( root->val >= val ? 1 : 0 ) +
            count_good_nodes( root->left, std::max( val, root->val ) ) +
            count_good_nodes( root->right, std::max( val, root->val ) );
    }
};

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
    struct tmp {
        tmp( TreeNode *n, int v ) 
            : node{n}, val{v}{}
        TreeNode *node{ nullptr };
        int val{ 0 };
    };

    int goodNodes(TreeNode* root)
    {
        std::queue<tmp> st;
        st.emplace( root, INT_MIN );
        int res{ 0 };
        while( !st.empty() ) {
            auto p = st.front();
            st.pop();

            if( p.node->val >= p.val )
                ++res;
            
            if( p.node->left )
                st.emplace( p.node->left, std::max( p.node->val, p.val ) );
            
            if( p.node->right )
                st.emplace( p.node->right, std::max( p.node->val, p.val ) );            
        }
        
        return res;
    }
};
