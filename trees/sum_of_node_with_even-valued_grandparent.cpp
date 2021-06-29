/**
 [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
[4,null,2,3,5,6,null,7,8,7,8,11,12,null,19,11,13,14,null,21,22,23,14]
[1]
[1,2]
[4,3,1,2,3,5,6]
[9,3,1,2,3,5,6]
 */
class Solution {
public:
    // space O( N ), where N is a number of nodes in a tree
    // time O( N ), where N is a number of nodes in a tree
    int sumEvenGrandparent( TreeNode* root )
    {
        if( !root )
            return 0;
        
        int sum{ 0 };
        if( ( root->val % 2 ) == 0 ) {
            if( root->left ) {
                auto l = root->left;
                sum += ( l->left ) ? l->left->val : 0;
                sum += ( l->right ) ? l->right->val : 0;
            }
            
            if( root->right ) {
                auto r = root->right;
                sum += ( r->left ) ? r->left->val : 0;
                sum += ( r->right ) ? r->right->val : 0;
            }            
        }
        
        return sum + sumEvenGrandparent( root->left ) + 
            sumEvenGrandparent( root->right );
    }
};

// space O( N ), where N is a number of nodes in a tree
// time O( N ), where N is a number of nodes in a tree
int sumEvenGrandparent( TreeNode* root, int p = 1, int grp = 1 )
{
  return root ? sumEvenGrandparent( root->left, root->val, p ) +
         sumEvenGrandparent( root->right, root->val, p ) +
         ( grp % 2 ? 0 : root->val ) : 0;
}

/**
 */
class Solution {
public:
    // space O( N ), where N is the number of nodes ( in reality in the queue there is maximum number of nodes in the biggest level )
    // time O( N ), where N is the number of ndoes
    int sumEvenGrandparent(TreeNode* root)
    {
        if( !root )
            return 0;
        
        std::queue<TreeNode *> q;
        q.push( root ); // O( 1 )
        int sum{ 0 };
        while( !q.empty() ) { // O( 1 )
            auto node = q.front(); // O( 1 )
            q.pop(); // O( 1 )
            if( node->val % 2 == 0 ) {
                if( node->left ) {
                    auto l = node->left;
                    sum += l->left ? l->left->val : 0;
                    sum += l->right ? l->right->val : 0;
                }
                
                if( node->right ) {
                    auto r = node->right;
                    sum += r->left ? r->left->val : 0;
                    sum += r->right ? r->right->val : 0;
                }
            }
            
            if( node->left )
                q.push( node->left );  // O( 1 )
            
            if( node->right )
                q.push( node->right ); // O( 1 )    
        }
        
        return sum;
    }
};
