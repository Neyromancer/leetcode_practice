class Solution {
    std::unordered_set<int> visited;
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int index = 0;
        int val = std::numeric_limits<int>::min();
        for( int i = 0; i < nums.size(); ++i ) {
            if( val < nums[ i ] ) {
                index = i;
                val = nums[ i ];
            }
        }

        TreeNode* root = new TreeNode( val );
        visited.insert( index );
        root->left = build_tree( nums, 0, index );
        root->right = build_tree( nums, index + 1, nums.size() );
        return root;
    }
    
    TreeNode* build_tree( const vector<int>& nums, int start, int end ) {
        if( start == end )
            return nullptr;

        int index = start;
        for( int i = start; i < end; ++i ) {
            if( nums[ index ] < nums[ i ] )
                index = i;
        }
        
        visited.insert( index );
        TreeNode* root = new TreeNode( nums[ index ] );
        root->left = build_tree( nums, start, index );
        root->right = build_tree( nums, index + 1, end );
        return root;        
    }
};
