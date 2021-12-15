/*
[[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]]
[[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
[[1,1,1,1,0,0],[1,1,0,1,0,0],[1,0,0,1,1,1],[1,1,1,0,0,1],[1,1,1,1,1,0],[1,0,1,0,1,0],[0,1,1,1,0,1],[1,0,0,0,1,1],[1,0,0,0,1,0],[1,1,1,1,1,0]]
[[1,1,1,1,0,1],[0,0,1,0,1,0],[1,1,1,1,1,1],[0,1,1,1,1,1],[1,1,1,0,1,0],[0,1,1,1,1,1],[1,1,0,1,1,1],[1,0,0,1,0,1],[1,1,1,1,1,1],[1,0,0,1,0,0]]
*/

class UF {
    std::vector<int> ranks;
    std::vector<int> parents;
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
    
    bool are_connected( int x, int y ) {
        return find( x ) == find( y );
    }
};

class Solution {
public:
    // time O( N * M )
    // space O( N * M )
    UF build_uf( const vector<vector<int>>& grid ) {
        int h = grid.size(); /// O( 1 )
        int w = grid.front().size(); // O( 1 )
        UF uf( w * h );
        std::vector<std::vector<int>> moves{ { 0, 1 }, { 1, 0 } };
        auto point = [w]( int x, int y ){
            return y * w + x;
        };

        for( int i = 0; i < h; ++i ) {
            for( int j = 0; j < w; ++j ) {
                if( !grid[ i ][ j ] ) // O( 1 )
                    continue;

                for( const auto& move : moves ) {
                    auto y = i + move[ 1 ];
                    auto x = j + move[ 0 ];
                    if( x >= w || y >= h || !grid[ y ][ x ] )
                        continue;
                    
                    uf.unite( point( j, i ), point( x, y ) );
                }
            }
        }
        
        return uf;
    }
    
    // time O( ( N * M )
    // space O( N * M )
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        auto uf1 = build_uf( grid1 ); // O( N * M )
        auto uf2 = build_uf( grid2 ); // O( N * M )

        int h = grid2.size();
        int w = grid2.front().size();
        auto point = [w]( int x, int y ) {
            return y * w + x;
        };

        std::unordered_map<int, std::vector<std::pair<int, int>>> islands2;
        for( int i = 0; i < h; ++i ) {
            for( int j = 0; j < w; ++j ) {
                if( !grid2[ i ][ j ] )
                    continue;
                
                islands2[ uf2.find( point( j, i ) ) ].push_back( std::make_pair( i, j ) );
            }
        }
        
        int cnt{ 0 };
        for( const auto& [root, lands] : islands2 ) {
            std::unordered_set<int> islands;
            bool is_water{ false };
            for( const auto& coord : lands ) {
                if( !grid1[ std::get<0>( coord ) ][ std::get<1>( coord ) ] ) {
                    is_water = true;
                    break;
                }
                
                islands.insert( uf1.find( point( std::get<1>( coord ), std::get<0>( coord ) ) ) );
            }

            if( !is_water && islands.size() == 1 )
                ++cnt;
        }

        
        return cnt;
    }
};
