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
    // time O( N log( N ) )
    // space ( O( N ) )
    TreeNode* removeLeafNodes(TreeNode* root, int target)
    {
        std::stack<TreeNode *> st;
        TreeNode *curr = root;
        TreeNode *prev = nullptr;
        while( !st.empty() || curr ) {
            while( curr ) { // O( lon( root.length ) ) tree's height
                st.push( curr ); // O( 1 )
                curr = curr->left;
            }
            
            curr = st.top(); // O( 1 )
            if( curr->right != prev && curr->right ) {
                curr = curr->right;
                continue;
            }
            
            st.pop(); // O( 1 )
            if( !curr->left && !curr->right && curr->val == target ) {
                if( st.empty() ) // O( 1 )
                    return nullptr;
                else if( st.top()->left == curr )
                    st.top()->left = nullptr;
                else
                    st.top()->right = nullptr;
            }
            
            prev = curr;
            curr = nullptr;
        }
        
        return root;
    }
};

class Solution {
public:
    // space O( log( N ) ) - tree height
    // time O( N ) - in the worst case check all the nodes
    TreeNode* removeLeafNodes(TreeNode* root, int target)
    {
        if( !root )
            return root;
        
        if( root->left )
            root->left = removeLeafNodes( root->left, target );
        
        if( root->right )
            root->right = removeLeafNodes( root->right, target );
        
        if( !root->right && !root->left && root->val == target )
            return nullptr;
        
        return root;
    }
};
