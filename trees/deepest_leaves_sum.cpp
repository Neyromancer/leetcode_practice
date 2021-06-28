// BFS
class Solution {
public:
    // space O( N ), where N is the number of nodes on the level
    // time O( N ), where N is the number of nodes in the tree
    int deepestLeavesSum( TreeNode* root )
    {
        if( !root || ( !root->left && !root->right ) )
            return !root ? 0 : root->val;
        
        int sum{ 0 };
        std::queue<TreeNode*> q;
        q.push( root );
        // time O( N ), where N == q.size()
        while( !q.empty() ) {
            auto sz = q.size();
            sum = 0;
            for( std::size_t i = 0; i < sz; ++i ) {
                auto node = q.front(); // O( 1 )
                q.pop(); // O( 1 )
                
                sum += node->val;
                if( node->left )
                    q.push( node->left ); // O( 1 )
                
                if( node->right )
                    q.push( node->right ); // O( 1 )
            }
        }
        
        return sum;
    }
};

// DFS
class Solution {
public:
    
    // time O( N ), where N is the number of nodes
    // space O( N ), where N is the number of nodes
    int deepestLeavesSum(TreeNode* root)
    {
        if( !root || ( !root->left && !root->right ) )
            return !root ? 0 : root->val;
        
        auto theight = count_height( root );
        return calc_sum( theight, root );
    }
    
    // time O( log N ), where N is the number of nodes
    // space O( N ), where N is the number of nodes
    int count_height( TreeNode *root )
    {
        if( !root )
            return 0;
        
        return 1 + std::max( count_height( root->left ), count_height( root->right ) );
    }
    
    // time O( log N ), where N is the number of nodes
    // space O( N ), where N is the number of nodes
    int calc_sum( int height, TreeNode *root )
    {
        if( !root )
            return 0;
        
        if( height == 1 )
            return root->val;
        
        return calc_sum( height - 1, root->left ) +
            calc_sum( height - 1, root->right );
    }
};

// DFS ( v2 )
class Solution {
    int res{ 0 };
    int mlvl{ 0 };
public:
    // space O( N ), where N is the number of nodes in the tree
    // time O( N ), where N is the number of nodes in the tree
    int deepestLeavesSum(TreeNode* root)
    {
        if( !root )
            return 0;
        
        sum_nodes( root, 0 );
        return res;
    }
    
    void sum_nodes( TreeNode *root, int lvl )
    {
        if( !root )
            return;
        
        if( lvl == mlvl ) {
            res += root->val;
        } else if( lvl > mlvl ) {
            res = root->val;
            mlvl = lvl;
        }
        
        sum_nodes( root->left, lvl + 1 );
        sum_nodes( root->right, lvl + 1 );
    }
};
