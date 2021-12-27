class Solution {
public:
    // time O( N )
    // space O( log N )
    TreeNode* tree_to_ll( TreeNode* root ) {
        if( !root )
            return nullptr;

        auto tmp = root->right;
        root->right = tree_to_ll( root->left );
        root->left = nullptr;
        auto cur = root;
        while( cur && cur->right )
            cur = cur->right;

        if( cur )
            cur->right = tree_to_ll( tmp );
        
        return root;
    }

     // time O( N )
    // space O( log N )
    void flatten(TreeNode* root) {
        root = tree_to_ll( root );
    }
};
