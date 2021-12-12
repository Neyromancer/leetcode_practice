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
        if( xroot == yroot )
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
    bool containsCycle(vector<vector<char>>& grid) {
        int w = grid.front().size();
        auto point = [w]( int y, int x ){
            return w * y + x;
        };
        
        int ch = 0;
        while( ch <= 26) {
            DSU dsu( grid.size() * grid.front().size() );
            for( int i = 0; i < grid.size(); ++i ) {
                for( int j = 0; j < grid[ i ].size(); ++j ) {
                    if( j + 1 < grid.front().size() && dsu.connected( point( i, j ), point( i, j + 1 ) ) )
                        return true;
                    
                    if( i + 1 < grid.size() && dsu.connected( point( i, j ), point( i + 1, j ) ) )
                        return true;

                    if( i + 1 < grid.size() && (char)( ch + 'a' ) == grid[ i ][ j ] &&
                       (char)( ch + 'a' ) == grid[ i + 1 ][ j ] )
                        dsu.unite( point( i, j ), point( i + 1, j ) );

                    if( j + 1 < grid.front().size() && (char)( ch + 'a' ) == grid[ i ][ j ] &&
                       (char)( ch + 'a' ) == grid[ i ][ j + 1 ] )
                        dsu.unite( point( i, j ), point( i, j + 1 ) );
                }
            }
            
            ++ch;
        }
        
        return false;
    }
};
