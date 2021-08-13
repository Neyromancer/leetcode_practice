class Solution {
public:
    TreeNode* lowestCommonAncestor( TreeNode* root, TreeNode* p, TreeNode* q )
    {
        if( !root )
            return nullptr;
        TreeNode *res{ nullptr };
        postorder_traverse( root, p, q, res );
        return res;
    }
   
    // O( N ), where N is nodes in the tree
    // O( N ), where N is all nodes in the tree 
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
    // O( N ), where N is nodes in the tree
    // O( N ), where N is all nodes in the tree 
    TreeNode* lowestCommonAncestor( TreeNode* root, TreeNode* p, TreeNode* q )
    {
        if( !root )
            return root;
        
        if( root->val < p->val && root->val < q->val )
            return lowestCommonAncestor( root->right, p, q );
        
        if( root->val > p->val && root->val > q->val )
            return lowestCommonAncestor( root->left, p, q );
        
        return root;
    }
};

class Solution {
public:
    // time O( N ), where N is the number of nodes in the BST
    // space O( 1 )
    TreeNode* lowestCommonAncestor( TreeNode* root, TreeNode* p, TreeNode* q )
    {
        if( !root )
            return root;
        
        while( root ) {
            if( root->val < p->val && root->val < q->val )
                root = root->right;
            else if( root-> val > p->val && root->val > q->val )
                root = root->left;
            else return root;
        }
        
        return nullptr;
    }
};
