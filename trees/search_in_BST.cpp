class Solution {
public:
    // time O( H ), where H is the height of the tree
    // space O( H ), where H is the height the tree
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
    // time O( H ), where H is the height of the tree
    // space O( H ), where H is the height of the tree
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

class Solution {
public:
    // time O( H ), where H is the height of the tree
    // space O( 1 )
    TreeNode* searchBST( TreeNode* root, int val )
    {
        while( root && root->val != val ) {
            if( root->val > val )
                root = root->left;
            else
                root = root->right;
        }
        
        return root;
    }
};
