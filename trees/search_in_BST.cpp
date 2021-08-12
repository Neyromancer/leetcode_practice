class Solution {
public:
    // time O( N ), where N is the number of nodes in the tree
    // space O( N ), where N is the number of nodes in the tree
    TreeNode* searchBST( TreeNode* root, int val )
    {
        if( !root )
            return nullptr;
        
        if( root->val == val )
            return root;
        
        if( root->val > val )
            return searchBST( root->left, val );
        
        return searchBST( root->right, val );
    }
};

class Solution {
public:
    // time O( N ), where N == number of nodes in the tree
    // space O( N ), where N == number of nodes in the tree
    TreeNode* searchBST( TreeNode* root, int val )
    {
        if( !root )
            return nullptr;

        std::queue<TreeNode*> q;
        q.push( root );
        while( !q.empty() ) {
            auto node = q.front();
            q.pop();
            if( !node )
                return node;
            
            if( node->val == val )
                return node;
            
            if( node->val > val )
                q.push( node->left );
            else
                q.push( node->right );
        }
        
        return nullptr;
    }
};
