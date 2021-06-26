// recursive
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        if( !root )
            return {};
        
        std::vector<int> res;
        traverse( root, res );
        return res;
    }
    
    void traverse( TreeNode *root, std::vector<int> &vc )
    {
        if( !root )
            return;
        
        traverse( root->left, vc );
        traverse( root->right, vc );
        vc.push_back( root->val );
    }
};

// iterative

