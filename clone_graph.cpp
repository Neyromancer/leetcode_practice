class Solution {
    std::unordered_map<std::uint8_t, Node*> visited;
public:
    Node* cloneGraph(Node* node)
    {
        if( !node )
            return nullptr;

        Node *res = new Node( node->val );
        visited[ node->val ] = res;
        for( auto n : node->neighbors ) {
            if( n && visited.count( n->val ) ) {
                res->neighbors.push_back( visited[ n->val ] );
                continue;
            }
            
            res->neighbors.push_back( cloneGraph( n ) );
        }
        
        return res;
    }
};
