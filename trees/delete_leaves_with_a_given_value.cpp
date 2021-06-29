// DFS recursive
class Solution {
public:
    // time O( N ), where N is the number of nodes in the tree
    // space O( N ), where N is the number of nodes in the tree
    TreeNode* removeLeafNodes(TreeNode* root, int target)
    {
        if( !root )
            return nullptr;

        root->left = removeLeafNodes( root->left, target );
        root->right = removeLeafNodes( root->right, target );
        if( !root->left && !root->right && root->val == target )
            return nullptr; 
        
        return root;
    }
};

// DFS iterative

// BFS
