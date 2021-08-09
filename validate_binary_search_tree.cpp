class Solution {
public:
    // O( N ), N == number of nodes in the tree
    bool is_ascending( const std::vector<int> &vc )
    {
        for( std::size_t i = 1; i < vc.size(); ++i )
            if( vc[ i - 1 ] >= vc[ i ] )
                return false;
        return true;
    }
    
    void traverse_inorder( TreeNode *root, std::vector<int> &vc )
    {
        if( !root )
            return;
        
        traverse_inorder( root->left, vc );
        vc.push_back( root->val );
        traverse_inorder( root->right, vc );
    }

    // time O( N ), N == number of nodes in the tree
    // space O( N ), N == number of nodes in the tree
    bool isValidBST( TreeNode* root )
    {
        if( !root )
            return true;
        
        std::vector<int> nodes;
        traverse_inorder( root, nodes );
        
        return is_ascending( nodes );
    }
};

class Solution {
public:
    // time O( N ), where N == number of nodes
    // space O( N ), where N == number of nodes
    bool isValidBST(TreeNode* root)
    {
        if( !root )
            return true;
        
        return validate( root, nullptr, nullptr );
    }
    
    bool validate( TreeNode *root, TreeNode *low, TreeNode *high )
    {
        if( !root )
            return true;
        
        if( ( low && ( root->val <= low->val ) ) || 
            ( high && ( root->val >= high->val ) ) )
            return false;
        
        return validate( root->right, root, high ) && 
            validate( root->left, low, root );
    }
};
