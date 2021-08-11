class BSTIterator {
    TreeNode *m_root{ nullptr };
    std::stack<TreeNode *> stk;
public:
    BSTIterator( TreeNode* root )
    {
        m_root = root;
        while( m_root ) {
            stk.push( m_root );
            m_root = m_root->left;
        }
    }
    
    int next()
    {
        auto node = stk.top();
        stk.pop();
        m_root = node->right;
        while( m_root ) {
            stk.push( m_root );
            m_root = m_root->left;
        }
        
        return node->val;
    }
    
    bool hasNext()
    {
        return !stk.empty() || m_root;
    }
};

