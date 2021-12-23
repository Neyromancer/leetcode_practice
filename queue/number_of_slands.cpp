class Solution {
public:
    // time O( N * M )
    // space O( N * M )
    int numIslands(vector<vector<char>>& grid)
    {
        int islands_num{ 0 };
        vector<vector<bool>> visited( grid.size(), std::vector<bool>( grid.front().size() ) );
        std::queue<std::vector<int>> island;
        
        auto is_valid = [&grid]( int y, int x ){
            return y >= 0 && y < grid.size() && x >= 0 && x < grid.front().size();
        };
        
        std::vector<std::vector<int>> directions{ { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        for( int i = 0; i < grid.size(); ++i ) {
            for( int j = 0; j < grid[ i ].size(); ++j ) {
                if( grid[ i ][ j ] == '1' && !visited[ i ][ j ] ) {
                    ++islands_num;
                    island.push( { i, j } );
                    visited[ i ][ j ] = true; // O( 1 )
                    while( !island.empty() ) { // O( sizeof( islands ) )
                        auto coords = island.front(); // O( 1 )
                        island.pop(); // O( 1 )
                        for( const auto& direction : directions ) { // O( sizeof( directions ) )
                            int dy = coords[ 0 ] + direction[ 0 ]; // O( 1 )
                            int dx = coords[ 1 ] + direction[ 1 ]; // O( 1 )
                            if( !is_valid( dy, dx ) || visited[ dy ][ dx ] || grid[ dy ][ dx ] == '0' )
                                continue;
                            
                            visited[ dy ][ dx ] = true; // O( 1 )
                            island.push( { dy, dx } ); // O( 1 )
                        }
                    }
                }
            }
        }
        
        return islands_num;
    }
};
