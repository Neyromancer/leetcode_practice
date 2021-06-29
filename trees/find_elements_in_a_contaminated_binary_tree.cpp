// DFS
class FindElements {
    std::unordered_set<int> st;
public:
    // space O( N ), N is the number of nodes
    // time O( N ), N is the number of nodes 
    FindElements( TreeNode* root ) {
        if( !root )
            return;
        
        root->val = 0;
        recover( root );
    }
    
    bool find( int target )
    {
        if( st.empty() )
            return false;

        return st.count( target ) == 1;
    }
    
    void recover( TreeNode *&root )
    {
        if( !root )
            return;
        
        st.insert( root->val );
        if( root->left )
            root->left->val = 2 * root->val + 1;
        
        if( root->right )
            root->right->val = 2 * root->val + 2;
        
        recover( root->left );
        recover( root->right );
    }
};

// BFS
class FindElements {
    std::unordered_set<int> st;
public:
   // space O( N ), where N is the number of nodes in the tree ( in reality equal to number of nodes in the largest level )
   // time O( N ), where N is the number of nodes
    FindElements(TreeNode* root)
    {
        if( !root )
            return;
        
        root->val = 0;
        recover( root );
    }
    
    // time O( 1 )
    // space O( 1 )
    bool find( int target )
    {
        if( st.empty() )
            return false;
        
        return st.count( target ) == 1; // O( 1 )
    }
    
    void  recover( TreeNode *root )
    {
        if( !root )
            return;
        
        std::queue<TreeNode *> q;
        q.push( root );
        while( !q.empty() ) {
            auto node = q.front();
            q.pop();

            st.insert( node->val );
            if( node->left ) {
                node->left->val = 2 * node->val + 1;
                q.push( node->left );
            }

            if( node->right ) {
                node->right->val = 2 * node->val + 2;
                q.push( node->right );
            }
        }
    }
};
