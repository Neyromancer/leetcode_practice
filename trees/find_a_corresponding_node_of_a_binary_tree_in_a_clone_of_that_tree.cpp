// DFS
// space O( H ), where H is the tree height
// time O( N ), N is the number of nodes in the tree
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        if( !original && !cloned )
            return nullptr;
        
        if( original == target )
            return cloned;
        
        auto left = getTargetCopy( original->left, cloned->left, target );
        auto right = getTargetCopy( original->right, cloned->right, target );
        
        return left ? left : right;
    }
};


// BFS
class Solution {
public:
    // space O( N / 2 ), where N / 2 is equal to the number of nodes at the largest level ( nearly halg of all nodes in the tree )
    // time O( N ), where N is the number of nodes in the tree
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        if( !original && !cloned )
            return nullptr;
        
        std::queue<TreeNode *> cq;
        std::queue<TreeNode *> oq;
        cq.push( cloned );
        oq.push( original );
        while( !oq.empty() && !cq.empty() ) {
            auto sz = oq.size();
            for( std::size_t i = 0; i < sz; ++i ) {
                auto onode = oq.front();
                auto cnode = cq.front();
                oq.pop();
                cq.pop();
                
                if( onode == target )
                    return cnode;
                
                if( onode->left && cnode->left ) {
                    oq.push( onode->left );
                    cq.push( cnode->left );
                }

                if( onode->right && cnode->right ) {
                    oq.push( onode->right );
                    cq.push( cnode->right );
                }                
            }
        }
        
        return nullptr;
    }
};


