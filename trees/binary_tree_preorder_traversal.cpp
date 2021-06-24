// recursive
class Solution {
public:
    // time O( N ), where N == num of nodes in a tree
    // space O( N ), where N == num of nodes in a tree
    vector<int> preorderTraversal(TreeNode* root)
    {
        if( !root )
            return {};
        
        std::vector<int> res;
        traverse( root, res );
        return res;
    }
    
    void traverse( TreeNode *root, std::vector<int> &res )
    {
        if( !root )
            return;
        
        res.push_back( root->val );
        traverse( root->left, res );
        traverse( root->right, res );
    }
};

// iterative
class Solution {
public:
    // space O( N ), where N is the number of nodes in the tree
    // time O( N ), where N is the number of nodes in the tree
    vector<int> preorderTraversal(TreeNode* root)
    {
        if( !root )
            return {};
        
        std::vector<int> res;
        std::stack<TreeNode*> st;
        while( !st.empty() || root ) {
            while( root ) {
                res.push_back( root->val );
                if( root->right )
                    st.push( root->right ); // O( 1 )
                
                root = root->left;
            }
            
            if( st.empty() )
                break;

            root = st.top(); // O( 1 )
            st.pop(); // O( 1 )
        }
        
        return res;
    }
};
