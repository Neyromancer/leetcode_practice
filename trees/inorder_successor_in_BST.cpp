class Solution {
public:
    // time O( N ), N == number of nodes in the tree
    // space O( N ), where N == number of nodes in the tree
    TreeNode* inorderSuccessor( TreeNode* root, TreeNode* p )
    {
        if( !root || !p )
            return nullptr;
        
        TreeNode *res{ nullptr };
        inorder( root, p, res );
        return res;
    }
    
    void inorder( TreeNode *root, TreeNode *p, TreeNode* &res )
    {
        if( !root )
            return;
        
        inorder( root->left, p, res );
        
        if( !res && root->val > p->val )
            res = root;
        
        inorder( root->right, p, res );
    }
};

class Solution {
public:
    // time O( N ), where N == number of nodes in the tree
    // space O( N ),m where N == number of nodes in the tree
    TreeNode* inorderSuccessor( TreeNode* root, TreeNode* p ) 
    {
        if( !root || !p )
            return nullptr;
        
        std::stack<TreeNode *> stk;
        while( !stk.empty() || root ) {
            while( root ) {
                stk.push( root );
                root = root->left;
            }
            
            auto node = stk.top();
            stk.pop();
            if( node && node->val > p->val )
                return node;
            
            root = node->right;
        }
        
        return nullptr;
    }
};

class Solution {
public:
    // time O( H ), where H == is the hight of the tree
    // space O( 1 )
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
    {
        if( !root || !p )
            return nullptr;
        
        TreeNode *res{ nullptr };
        while( root ) {
            if( root->val > p->val )
                res = root;
            
            if( p->val >= root->val )
                root = root->right;
            else
                root = root->left;
        }
        
        return res;
    }
};
