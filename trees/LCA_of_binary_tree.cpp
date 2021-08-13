class Solution {
public:
    // O( N ), where N is the number of nodes in the tree
    // O( N ), where N is the number of nodes in the tree
    TreeNode* lowestCommonAncestor( TreeNode* root, TreeNode* p, TreeNode* q )
    {
        if( !root )
            return root;
        
        TreeNode *res{ nullptr };
        postorder_traverse( root, p, q, res );
        return res;
    }
    
    bool postorder_traverse( TreeNode *root, TreeNode *p, TreeNode *q, TreeNode* &res )
    {
        if( !root )
            return false;
        
        auto l = postorder_traverse( root->left, p, q, res );
        auto r = postorder_traverse( root->right, p, q, res );
        
        if( !res && l && r ) {
            res = root;
            return true;
        }
        
        if( !res && ( ( l || r ) && ( root == p || root == q ) ) ) {
            res = root;
            return true;
        }
        
        if( root == p || root == q )
            return true;
        
        return l || r;
    }
};

class Solution {
public:
    // O( N ), where N is the number of nodes in the tree
    // O( N ), where N is the number of nodes in the tree
    TreeNode* lowestCommonAncestor( TreeNode* root, TreeNode* p, TreeNode* q )
    {
        if( !root )
            return root;
        
        std::unordered_map<TreeNode *, TreeNode *> m;
        std::queue<TreeNode *> st;
        st.push( root );
        m[ root ] = nullptr;
        while( !m.count( p ) || !m.count( q ) ) {
            auto node = st.front();
            st.pop();
            if( !node )
                continue;
            
            m[ node->left ] = node;
            m[ node->right ] = node;
            st.push( node->left );
            st.push( node->right );
        }
        
        std::set<TreeNode *> ancestors;
        while( p ) {
            ancestors.insert( p );
            p = m[ p ];
        }
        
        while( !ancestors.count( q ) )
            q = m[ q ];
        
        return q;
    }
};
