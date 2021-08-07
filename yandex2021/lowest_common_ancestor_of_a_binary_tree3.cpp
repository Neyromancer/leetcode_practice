/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    // time O( N x logN + M ), N == nodes( p ), M == nodes( q )
    // space O( N ), N == nodes( p )
    Node* lowestCommonAncestor( Node* p, Node * q )
    {
        std::set<Node *> st;
        while( p ) {
            st.insert( p );
            p = p->parent;
        }
        
        while( q ) {
            if( st.count( q ) )
                return q;
            
            q = q->parent;
        }
        
        return nullptr;
    }
};

class Solution {
public:
    // time O( H ), where H - height of the tree
    // space O( 1 )
    int get_height( Node *p )
    {
        int h{ 0 };
        while( p ) {
            ++h;
            p = p->parent;
        }
        
        return h;
    }

    // time O( H ), where H - height of the tree
    // space O( 1 )    
    Node* lowestCommonAncestor(Node* p, Node * q)
    {
        int pheight = get_height( p );
        int qheight = get_height( q );
        if( pheight < qheight ) {
            auto tmp = p;
            p = q;
            q = tmp;
        }
        
        auto hdiff = std::abs( pheight - qheight );
        while( hdiff > 0 && p ) {
            p = p->parent;
            --hdiff;
        }
        
        while( p != q ) {
            p = p->parent;
            q = q->parent;
        }
        
        return p;
    }
};

class Solution {
public:
    // time O( H ), where H is the height of the tree
    // space O( 1 )
    Node* lowestCommonAncestor( Node* p, Node * q )
    {
        auto p1 = p;
        auto p2 = q;
        while( p1 != p2 ) {
            p1 = !p1 ? q : p1->parent;
            p2 = !p2 ? p : p2->parent;
        }
        
        return p1;
    }
};
