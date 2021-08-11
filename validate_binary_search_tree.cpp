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

class Solution {
public:
    // time O( N ), where N == number of nodes in the tree
    // space O( N ), where N == number of nodes in the tree
    bool isValidBST( TreeNode* root )
    {
        std::stack<TreeNode *> stk;
        std::stack<TreeNode *> lower_limits;
        std::stack<TreeNode *> above_limits;
        
        auto update = [ &stk, &lower_limits, &above_limits ]( TreeNode *cur, TreeNode *lborder, TreeNode *rborder ) {
            stk.push( cur );
            lower_limits.push( lborder );
            above_limits.push( rborder );
        };
        
        update( root, nullptr, nullptr );
        while( !stk.empty() ) {
            auto node = stk.top();
            stk.pop();
            auto low = lower_limits.top();
            lower_limits.pop();
            auto high = above_limits.top();
            above_limits.pop();
            
            if( !node )
                continue;
            
            if( low && low->val >= node->val )
                return false;
            
            if( high && high->val <= node->val )
                return false;
            
            update( node->right, node, high );
            update( node->left, low, node );
        }
        
        return true;
    }
};

class Solution {
    TreeNode *prev{ nullptr };
public:
    // time O( N ), where N == nodes in the tree
    // space O( N ), where N == nodes in the tree
    bool isValidBST(TreeNode* root)
    {
        return inorder( root );
    }
    
    bool inorder( TreeNode *root )
    {
        if( !root )
            return true;
        
        if( !inorder( root->left ) )
            return false;
        
        if( prev && prev->val >= root->val )
            return false;
        
        prev = root;
        return inorder( root->right );
    }
};

class Solution {
public:
    // time O( N ), where N == number of nodes in the tree
    // space O( N ), where N == number of nodes in the tree
    bool isValidBST( TreeNode* root )
    {
        std::stack<TreeNode *> stk;
        TreeNode *prev{ nullptr };
        while( !stk.empty() || root ) {
            while( root ) {
                stk.push( root );
                root = root->left;
            }
            
            auto node = stk.top();
            stk.pop();
            if( prev && prev->val >= node ->val )
                return false;
            
            prev = node;
            root = node->right;
        }
        
        return true;
    }
};
