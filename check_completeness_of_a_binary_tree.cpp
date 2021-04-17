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
// [1,2,3,4,5]
/**
         1
       2    3
     4   5  

*/
class Solution {
public:
    // time O( number of nodes )
    // space O( number of nodes )
    bool isCompleteTree(TreeNode* root) 
    {
        std::queue<TreeNode *> st;
        st.push( root ); // O( 1 )
        while( !st.empty() ) { // O( number of nodes )
            auto node = st.front(); // O( 1 )
            st.pop(); // O( 1 )
            if( !node ) {
                while( !st.empty() && st.front() == nullptr ) 
                    st.pop(); // O( 1 )

                if( st.empty() ) // O( 1 )
                    return true;
                return false;
            }
            
            st.push( node->left ); // O( 1 )
            st.push( node->right ); // O( 1 )
        }

        return true;
    }
};

class Solution {
public:
    // time O( all nodes )
    // space O( all nodes )
    bool isCompleteTree(TreeNode* root)
    {
        std::vector<std::pair<TreeNode *,std::size_t>> nodes;
        nodes.push_back( { root, 1 } );
        std::size_t i = 0;
        while( i < nodes.size() ) {
            auto node = nodes.at( i++ );
            if( node.first ) {
                nodes.push_back( { node.first->left, node.second * 2 } );
                nodes.push_back( { node.first->right, node.second * 2 + 1 } );
            }
        }
        
        return nodes.at( i - 1 ).second == nodes.size();
    }
};

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
    bool isCompleteTree(TreeNode* root)
    {
        std::queue<TreeNode *> st;
        st.push( root );
        bool check{ false };
        while( !st.empty() ) {
            auto node = st.front();
            st.pop();
            if( node->left ) {
                if( check )
                    return false;
                st.push( node->left );
            } else {
                check = true;
            }
            
            if( node->right ) {
                if( check )
                    return false;
                
                st.push( node->right );
            } else {
                check = true;
            }
        }
        
        return true;
    }
};
