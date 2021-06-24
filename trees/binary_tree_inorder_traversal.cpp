// recursive
class Solution {
public:
    // time O( N ), where N is number of nodes in a tree
    // space O( N ), where N is the number of nodes in a tree
    vector<int> inorderTraversal(TreeNode* root)
    {
        if( !root )
            return {};
        
        std::vector<int> res;
        traverse( root, res );
        return res;
    }
    
    void traverse( TreeNode *head, std::vector<int> &vc )
    {
        if( !head )
            return;
        
        traverse( head->left, vc );
        
        vc.push_back( head->val ); // O( 1 )
        
        traverse( head->right, vc );
    }
};

// interative
class Solution {
public:
    // space O( N ), where N == number of nodes in a tree
    // time O( N ), where N == number of nodes in a tree
    vector<int> inorderTraversal(TreeNode* root)
    {
        if( !root )
            return {};
        
        std::vector<int> res;
        std::stack<TreeNode *> st;
        while( !st.empty() || root ) {
            while( root ) {
                st.push( root );  // O( 1 )
                root = root->left;
            }
            
            res.push_back( st.top()->val ); // ( O( 1 )
            root = st.top()->right; // O( 1 )
            st.pop(); // O( 1 )
        }
        
        return res;
    }
};
