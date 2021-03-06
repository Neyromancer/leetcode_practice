/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// space O( N ) N - tree nodes
// time O( N ) N - tree nodes
class Solution {
public:
    vector<int> largestValues(TreeNode* root)
    {
        if( !root )
            return {};
        
        std::queue<TreeNode *> storage;
        storage.push( root );
        std::vector<int> res;
        while( !storage.empty() ) {
            int sz = storage.size();
            int max_val{ INT_MIN };
            for( int i = 0; i < sz; ++i ) {
                auto node = storage.front();
                storage.pop();
                if( node->left )
                    storage.push( node->left );
                
                if( node->right )
                    storage.push( node->right );
                
                max_val = std::max( max_val, node->val );
            }
            
            res.push_back( max_val );
        }
        
        return res;
    }
};

// space O( N ), N - tree nodes
// time O( N ), N - tree nodes
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if( !root )
            return {};
        
        std::vector<int> res;
        find_lvl_largest( root, res, 0 );
        
        return res;
    }
    
    void find_lvl_largest( TreeNode *root, std::vector<int> &res, int lvl )
    {
        if( !root )
            return;
        
        if( res.size() == lvl )
            res.push_back( root->val );
        else
            res[ lvl ] = std::max( res[ lvl ], root->val );
        
        find_lvl_largest( root->left, res, lvl + 1 );
        find_lvl_largest( root->right, res, lvl + 1 );
    }
};
