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
    vector<int> rightSideView(TreeNode* root)
    {
        if( !root )
            return {};

        std::vector<int> res;
        std::queue<TreeNode *> st;
        st.push( root );
        while( !st.empty() ) {
            int size = st.size();
            while( size > 0 ) {
                auto node = st.front();
                st.pop();
                --size;
                
                if( !size )
                    res.push_back( node->val );
                
                if( node->left )
                    st.push( node->left );
                
                if( node->right )
                    st.push( node->right );
            }
        }
        
        return res;
    }
};

class Solution {
public:
    
    vector<int> rightSideView(TreeNode* root) {
        if( root == nullptr )
            return {};

        std::vector<int> res;
        res.push_back( root->val );
        int level = 0;
        parse_side( root->right, res, 1, level );
        parse_side( root->left, res, 1, level );
        
        return res;
    }
    
    void parse_side( TreeNode *root, std::vector<int> &vc, int current_level, int &level ) {
        if( root == nullptr )
            return;
        
        if( current_level > level ) {
          vc.push_back( root->val );
          level = current_level;
        }
        
        parse_side( root->right, vc, current_level + 1, level );         
        parse_side( root->left, vc, current_level + 1, level );       
    }
};
