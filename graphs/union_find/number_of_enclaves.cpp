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
        auto root_x = find( x );
        auto root_y = find( y );
        if( root_x == root_y )
            return;
        
        if( ranks[ root_x ] >= ranks[ root_y ] ) {
            ranks[ root_x ] += ranks[ root_y ];
            parents[ root_y ] = root_x;
        } else {
            ranks[ root_y ] += ranks[ root_x ];
            parents[ root_x ] = root_y;
        }
    }
    
    bool are_combined( int x, int y ) {
        return find( x ) == find( y );
    }
};
/*
[[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]

     0 1 2 3 4 5 6 7 8 9
[ 0 [0,0,0,1,1,1,0,1,0,0],  4
  1 [1,1,0,0,0,1,0,1,1,1],  6
  2 [0,0,0,1,1,1,0,1,0,0],  4
  3 [0,1,1,0,0,0,1,0,1,0],  4
  4 [0,1,1,1,1,1,0,0,1,0],  6
  5 [0,0,1,0,1,1,1,1,0,1],  6
  6 [0,1,1,0,0,0,1,1,1,1],  6
  7 [0,0,1,0,0,1,0,1,0,1],  4
  8 [1,0,1,0,1,1,0,0,0,0],  4
  9 [0,0,0,0,1,1,0,0,0,1] ] 3
 isalnds = 47
 islands_to_remove 3, 1, 1, 3, 1, 2, 1, 1
 
*/
class Solution {
    int h{ 0 }; // 10
    int w{ 0 }; // 10
public:
    // O( 1 )
    // O( 1 )
    int point( int y, int x )
    {
        return y * w + x;
    }
    
    // time O( N * M )
    // space O( N * M )
    int numEnclaves(vector<vector<int>>& grid)
    {
        if( grid.empty() || grid.front().empty() )
            return 0;

        h = grid.size(); // O( 1 )
        w = grid.front().size(); // O( 1 )

        DSU dsu( h * w );
        std::vector<std::vector<int>> directions{ { 1, 0, -1, 0 }, { 0, 1, 0, -1 } };
        int islands{ 0 };
        // O( N * M )
        for( int i = 0; i < h; ++i ) {
            for( int j = 0; j < w; ++j ) {
                if( grid[ i ][ j ] ) { // O( 1 )
                    ++islands;
                    for( int d = 0; d < directions.front().size(); ++d ) {
                        int x = j + directions[ 0 ][ d ]; // O( 1 )
                        int y = i + directions[ 1 ][ d ]; // O( 1 )
                        if( y >= 0 && y < h && x >= 0 && x < w && grid[ y ][ x ] ) {
                            dsu.unite( point( i, j ), point( y, x ) ); // O( 1 )
                        }
                    }
                }
            }
        }
        
        std::unordered_map<int, int> islands_to_remove;
        // O( N )
        for( int i = 0; i < h; ++i ) {
            if( grid[ i ][ 0 ] )
                ++islands_to_remove[ dsu.find( point( i, 0 ) ) ];
            
            if( grid[ i ][ w - 1 ] )
                ++islands_to_remove[ dsu.find( point( i, w - 1 ) ) ];
        }
        
        // O( M )
        for( int j = 1; j < w - 1; ++j ) {
            if( grid[ 0 ][ j ] )
                ++islands_to_remove[ dsu.find( point( 0, j ) ) ];
            
            if( grid[ h - 1 ][ j ] )
                ++islands_to_remove[ dsu.find( point( h - 1, j ) ) ];
        }
        
        // O( N * M )
        for( int i = 1; i < h - 1; ++i ) {
            for( int j = 1; j < w - 1; ++j ) {
                if( grid[ i ][ j ] && islands_to_remove.count( dsu.find( point( i, j ) ) ) )// O( 1 )
                    ++islands_to_remove[ dsu.find( point( i, j ) ) ]; // O( 1 )
            } 
        }

        // O( N + M )
        for( const auto&[ root, cnt ] : islands_to_remove )
            islands -= cnt;
        
        return islands <= 0 ? 0 : islands;
    }
};
