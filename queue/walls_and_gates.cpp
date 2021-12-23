class Solution {
    const uint64_t INF = 2147483647U;
public:
    void wallsAndGates(vector<vector<int>>& rooms) 
    {
        std::queue<std::vector<int>> cells;
        for( int i = 0; i < rooms.size(); ++i ) {
            for( int j = 0; j < rooms[ i ].size(); ++j ) {
                if( !rooms[ i ][ j ] )
                    cells.push( { i, j } );
            }
        }
        
        auto is_valid = [&rooms]( int y, int x ) -> bool {
            return y >= 0 && y < rooms.size() && x >= 0 && x < rooms.front().size();
        };
        
        std::vector<std::vector<int>> directions{ { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        while( !cells.empty() ) {
            auto coord = cells.front();
            cells.pop();

            int x = coord[ 1 ];
            int y = coord[ 0 ];
            if( rooms[ y ][ x ] < 0 )
                continue;

            for( const auto& dir : directions ) {
                int dx = x + dir[ 1 ];
                int dy = y + dir[ 0 ];

                if( !is_valid( dy, dx ) || rooms[ dy ][ dx ] != INF )
                    continue;

                if( !rooms[ y ][ x ] && rooms[ dy ][ dx ] > 0 ) {
                        rooms[ dy ][ dx ] = 1;
                } else {
                    if( rooms[ dy ][ dx ] >= 0 )
                        rooms[ dy ][ dx ] = std::min( rooms[ y ][ x ] + 1, rooms[ dy ][ dx ] );
                }

                cells.push( { dy, dx } );
            }
        }
    }
};
