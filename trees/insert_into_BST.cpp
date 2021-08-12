class Solution {
public:
    // time O( H ) where H is the height of the BST
    // space O( 1 )
    TreeNode* insertIntoBST( TreeNode* root, int val )
    {
        if( !root )
            return new TreeNode( val );

        auto head = root;
        while( root ) {
            if( root->val > val ) {
                if( root->left ) {
                    root = root->left;
                } else {
                    root->left = new TreeNode( val );
                    break;
                }
            } else {
                 if( root->right ) {
                    root = root->right;
                } else {
                    root->right = new TreeNode( val );
                    break;
                }   
            }
        }
        
        return head;
    }
};

class Solution {
public:
    // time O( H ) where H is the height of the BST
    // space O( 1 )
    TreeNode* insertIntoBST( TreeNode* root, int val )
    {
        if( !root )
            return new TreeNode( val );

        auto head = root;
        while( root ) {
            if( root->val > val ) {
                if( root->left ) {
                    root = root->left;
                } else {
                    root->left = new TreeNode( val );
                    break;
                }
            } else {
                 if( root->right ) {
                    root = root->right;
                } else {
                    root->right = new TreeNode( val );
                    break;
                }   
            }
        }
        
        return head;
    }
};

class Solution {
public:
    // time O( H ) where H is the height of the BST
    // space O( H ) where H is the height of the BST
    TreeNode* insertIntoBST( TreeNode* root, int val )
    {
        if( !root )
            return new TreeNode( val );
        
        if( root->val < val )
            root->right = insertIntoBST( root->right, val );
        else
            root->left = insertIntoBST( root->left, val );
        
        return root;
    }
};
