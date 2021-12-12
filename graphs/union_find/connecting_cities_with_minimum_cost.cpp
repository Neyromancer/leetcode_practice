class DSU {
    std::vector<int> parents;
    std::vector<int> ranks;
public:
    DSU( int size ) {
        parents.resize( size );
        std::iota( std::begin( parents ), std::end( parents ), 0 );
        ranks.resize( size, 1 );
    }
    
    int find( int x ) {
        if( x == parents[ x ] )
            return x;
        return find( parents[ x ] );
    }
    
    void unite( int x, int y ) {
        auto xroot = find( x );
        auto yroot = find( y );
        if( yroot == xroot )
            return;
        
        if( ranks[ xroot ] >= ranks[ yroot ] ) {
            parents[ yroot ] = xroot;
            ranks[ xroot ] += ranks[ yroot ];
        } else {
            parents[ xroot ] = yroot;
            ranks[ yroot ] += ranks[ xroot ];           
        }
    }
    
    bool connected( int x, int y ) {
        return find( x ) == find( y );
    }
};

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {        
        std::sort( std::begin( connections ), std::end( connections ), []( const auto& edge1, const auto& edge2 ){
            return edge1[ 2 ] < edge2[ 2 ];
        } );
        
        DSU dsu{ n + 1 };
        int total_cost{ 0 };
        int total_connections{ 0 };
        for( const auto& edge : connections ) {
            auto a = edge[ 0 ];
            auto b = edge[ 1 ];
            if( dsu.connected( a, b ) )
                continue;
            
            total_cost += edge[ 2 ];
            dsu.unite( a, b );
            ++total_connections;
        }
        
        return total_connections == n - 1 ? total_cost : -1;
    }
};
