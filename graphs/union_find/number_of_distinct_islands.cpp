class UF {
    std::vector<int> parents;
    std::vector<int> ranks;
public:
    UF( int size ) {
        ranks.resize( size, 1 );
        parents.resize( size );
        std::iota( std::begin( parents ), std::end( parents ), 0 );
    }
    
    int find( int x ) {
        if( x == parents[ x ] )
            return x;
        return find( parents[ x ] );
    }
    
    void merge( int x, int y ) {
        int root_x = find( x );
        int root_y = find( y );
        if( root_y == root_x )
            return;
        
        if( ranks[ root_x ] >= ranks[ root_y ] ) {
            ranks[ root_x ] += ranks[ root_y ];
            parents[ root_y ] = root_x;
        } else {
             ranks[ root_y ] += ranks[ root_x ];
            parents[ root_x ] = root_y;           
        }
    }
};

class Solution {
public:
    // time O( N * M )
    // space O( N * M )
    int numDistinctIslands(vector<vector<int>>& grid) {
        if( grid.empty() || grid.front().empty() )
            return 0;
        
        int h = grid.size();
        int w = grid.front().size();
        
        auto point = [w]( int y, int x ) {
            return y * w + x; 
        };
        
        UF uf( h * w );
        std::vector<std::vector<int>> direction = { { 1, 0, -1, 0 }, { 0, 1, 0, -1 } };
        for( int i = 0; i < h; ++i ) {
            for( int j = 0; j < w; ++j ) {
                if( grid[ i ][ j ] ) {
                    for( int d = 0; d < direction[ 0 ].size(); ++d ) {
                        auto y = i + direction[ 1 ][ d ];
                        auto x = j + direction[ 0 ][ d ];
                        if( y >= 0 && y < h && x >= 0 && x < w && grid[ y ][ x ] )
                            uf.merge( point( i, j ),
                                     point( i + direction[ 1 ][ d ], j + direction[ 0 ][ d ] ) ); // O( 1 )
                    }
                }
            }
        }
        
        std::unordered_map<int, std::vector<int>> components;
        for( int i = 0; i < h; ++i ) {
            for( int j = 0; j < w; ++j ) {
                if( grid[ i ][ j ] )
                    components[ uf.find( point( i, j ) ) ].push_back( point( i, j ) ); // O( 1 )
            }
        }
        
        std::unordered_set<std::uint64_t> res;
        for( const auto&[ root, connected_dots ] : components ) {
            int mini = root / w;
            int minj = w;
            for( auto j : connected_dots )
                minj = std::min( minj, j % w );
            
            std::uint64_t hash = 1;
            auto offset = point( mini, minj );
            const int MOD = 10e9 + 7;
            for( auto j : connected_dots )
                hash = ( hash * 31 + j - offset ) % MOD;
            res.insert( hash );
        }
        
        return res.size();
    }
};
