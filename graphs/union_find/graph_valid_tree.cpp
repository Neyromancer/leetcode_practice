class UnionFind {
    std::vector<int> ranks;
    std::vector<int> roots;
    int root_num{ 0 };
    
public:
    // time O( size )
    UnionFind( int size ) {
        ranks.resize( size );
        roots.resize( size );
        for( int i = 0; i < size; ++i ) {
            ranks[ i ] = 1;
            roots[ i ] = i;
        }
        
        root_num = size;
    }
    
    // time O( 1 ) ~ O( inverse akerman func( N ) )
    int find( int x ) {
        if( x == roots[ x ] )
            return x;
        return roots[ x ] = find( roots[ x ] );
    }
    
    // time O( 1 ) ~ O( inverse akerman func( N ) )
    void unite( int x, int y ) {
        int root_x = find( x );
        int root_y = find( y );
        if( root_x == root_y )
            return;
        
        if( ranks[ root_x ] > ranks[ root_y ] )
            roots[ root_y ] = root_x;
        else if( ranks[ root_y ] > ranks[ root_x ] )
            roots[ root_x ] = root_y;
        else {
            roots[ root_y ] = root_x;
            ++ranks[ root_x ];
        }
        
        --root_num;
    }
    
    // time O( 1 ) ~ O( inverse akerman func( N ) )
    bool connected( int x, int y ) {
        return find( x ) == find( y );
    }
    
    // O( 1 )
    int get_root_number() {
        return root_num;
    }
};

class Solution {
public:
    // space O( n )
    // time O( n )
    bool validTree(int n, vector<vector<int>>& edges)
    {
        UnionFind uf( n );
        for( int i = 0; i < edges.size(); ++i ) {
            if( uf.connected( edges[ i ][ 0 ], edges[ i ][ 1 ] ) ) // O( 1 )
                return false;
            
            uf.unite( edges[ i ][ 0 ], edges[ i ][ 1 ] ); // O( 1 )
        }
        
        return uf.get_root_number() == 1; // O( 1 )
    }
};
