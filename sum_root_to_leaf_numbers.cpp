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
class Solution {
public:
    int add( int n1, int n2 ) {
        return n1 * 10 + n2;
    }
    
    int sumNumbers(TreeNode* root)
    {
        if( !root )
            return 0;
        
        std::queue<std::pair<TreeNode *,int>> q;
        q.push( std::make_pair(root, root->val) );
        int sum{ 0 };
        while( !q.empty() ) {
            std::size_t sz = q.size();
            for( std::size_t i = 0; i < sz; ++i ) {
                auto [node, val] = q.front();
                q.pop();
                auto left = node->left;
                auto right = node->right;
                if(!left && !right) {
                    sum += val;
                    continue;
                }
                
                if(left)
                    q.push( std::make_pair( left, add(val, left->val) ) );
                
                if(right)
                    q.push( std::make_pair( right, add(val, right->val) ) );
            }
        }
        
        return sum;
    }
};
