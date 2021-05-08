// DFS
cass Solution {
public:
    // time O( N^2 ), where N is the size of edges
    // space O( N ), where N is the size of edges
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        std::vector<std::vector<int>> graph( 1001, std::vector<int>() );
        std::vector<int> res( 2 );
        for( int i = 0; i < edges.size(); ++i ) {
            std::unordered_set<int> seen;
            if( i && are_connected( graph, seen, edges[ i ][ 0 ], edges[ i ][ 1 ] ) ) {
                res[ 0 ] = edges[ i ][ 0 ]; // O( 1 )
                res[ 1 ] = edges[ i ][ 1 ]; // O( 1 )
            }
            
            graph[ edges[ i ][ 0 ] ].push_back( edges[ i ][ 1 ] ); // O( 1 )
            graph[ edges[ i ][ 1 ] ].push_back( edges[ i ][ 0 ] ); // O( 1 )
        }
        
        return res;
    }
    
    // space O( graph.size )
    // time O( graph.size )
    bool are_connected( const std::vector<std::vector<int>> &graph, std::unordered_set<int> &seen,
                        int val, int target )
    {
        if( !seen.count( val ) ) { // O( 1 )
            seen.insert( val ); // avr: O( 1 )
            
            if( val == target )
                return true;
            
            for( auto el : graph[ val ] ) {
                if( are_connected( graph, seen, el, target ) )
                    return true;
            }
        }
        
        return false;
    }
};

// Union Find
class UnionFind {
    std::vector<int> parents;
    std::vector<std::uint64_t> ranks;

public:
    UnionFind( int size )
    {
        parents.resize( size );
        for( int i = 0; i < size; ++i )
            parents[ i ] = i;
        
        ranks.resize( size );
        std::fill( std::begin( ranks ), std::end( ranks ), 1 );
    }
    
    int find_root( int i )
    {
        while( i != parents[ i ] )
            i = parents[ i ];
        
        return i;
    }
    
    void unite( int p, int q )
    {
        int pid = find_root( p );
        int qid = find_root( q );
        if( pid == qid )
            return;
        
        if( ranks[ pid ] > ranks[ qid ] ) {
            ranks[ pid ] += ranks[ pid ];
            parents[ qid ] = pid;
        } else {
            ranks[ qid ] += ranks[ pid ];
            parents[ pid ] = qid;
            
        }
    }
    
    bool connected( int p, int q )
    {
        return find_root( p ) == find_root( q );
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        UnionFind uf( 1001 );
        std::vector<int> res( 2 );
        for( const auto edge : edges ) {
            if( uf.connected( edge[ 0 ], edge[ 1 ] ) ) {
                res[ 0 ] = edge[ 0 ];
                res[ 1 ] = edge[ 1 ];
            } else {
                uf.unite( edge[ 0 ], edge[ 1 ] );
            }
        }
        
        return res;
    }
};
