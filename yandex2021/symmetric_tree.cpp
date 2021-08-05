class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        return check_symmetry( root, root );
    }
    
    bool check_symmetry( TreeNode *r1, TreeNode *r2 )
    {
        if( !r1 && !r2 )
            return true;
        
        if( ( r1 && !r2) || ( !r1 && r2 ) )
            return false;
        
        auto l = check_symmetry( r1->left, r2->right );
        auto r = check_symmetry( r1->right, r2->left );
        
        return r1->val == r2->val && r && l;
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        std::queue<TreeNode *> q;
        q.push( root );
        while( !q.empty() ) {
            auto sz = q.size();
            std::vector<TreeNode *> tmp;
            for( std::size_t i = 0; i < sz; ++i ) {
                auto node = q.front();
                if( node ) {
                    q.push( node->left );
                    q.push( node->right );
                }

                tmp.push_back( node );
                q.pop();
            }
            
            if( !is_symmetric( tmp ) )
                return false;
        }
        
        return true;
    }
    
    bool is_symmetric( const std::vector<TreeNode *> &vc )
    {
        int l{ 0 };
        int r = vc.size() - 1;
        while( l <= r ) {
            if( ( vc[ l ] && !vc[ r ] ) || ( !vc[ l ] && vc[ r ] ) )
                return false;
            
            if( vc[ l ] && vc[ r ] && 
               ( vc[ l ]->val != vc[ r ]->val ) )
                return false;
            
            ++l;
            --r;
        }
        
        return true;
    }

};
