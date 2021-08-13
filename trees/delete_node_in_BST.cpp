class Solution {
public:
    TreeNode *findSuccessor( TreeNode *root )
    {
        auto cur = root;
        while( cur && cur->left )
            cur = cur->left;
        return cur;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if( !root )
            return nullptr;
        
        if( root->val == key ) {
            if( !root->left )
                return root->right;
            
            if( !root->right )
                return root->left;
            
            auto node = findSuccessor( root->right );
            root->val = node->val;
            root->right = deleteNode( root->right, node->val );
            return root;
        } else if( root->val > key ) {
            root->left = deleteNode( root->left, key );
        } else {
            root->right = deleteNode( root->right, key );
        }
        
        return root;
    }
};
