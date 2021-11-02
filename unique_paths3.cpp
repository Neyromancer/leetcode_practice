class Solution {
    int cnt_path{ 0 };
    int cnt_nonblocking{ 0 };
public:
    std::pair<int,int> find_starting_ptr( const vector<vector<int>>& grid )
    {
        int x{ 0 };
        int y{ 0 };
        for( int i = 0; i < grid.size(); ++i ) {
            for( int j = 0; j < grid.front().size(); ++j ) {
                if( grid[ i ][ j ] == 1 ) {
                    y = i;
                    x = j;
                    break;
                }
            }
        }
        
        return {x, y};
    }
    
    int cnt_nonobstacles( const vector<vector<int>>& grid )
    {
        int cnt{ 0 };
        for( int i = 0; i < grid.size(); ++i ) {
            for( int j = 0; j < grid.front().size(); ++j ) {
                if( grid[ i ][ j ] >= 0 )
                    ++cnt;
            }
        }
        return cnt;
    }
    
    void dfs( vector<vector<int>>& grid, int x, int y )
    {
        if( x >= grid.front().size() || y >= grid.size() || x < 0 || y < 0 )
            return;
        
        if( grid[ y ][ x ] == 2 && cnt_nonblocking == 1 ) {
            ++cnt_path;
            return;
        }
        
        if( grid[ y ][ x ] < 0 )
            return;
        
        auto tmp = grid[ y ][ x ];
        grid[ y ][ x ] = -4;
        --cnt_nonblocking;

        std::vector<int> y_direction{ -1, 0, 1, 0 };
        std::vector<int> x_direction{ 0, -1, 0, 1 };
        for( int i = 0; i < y_direction.size(); ++i )
            dfs( grid, x + x_direction[ i ], y + y_direction[ i ] );


        grid[ y ][ x ] = tmp;
        ++cnt_nonblocking;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid)
    {
        const auto& [ x, y ] = find_starting_ptr( grid );
        cnt_nonblocking = cnt_nonobstacles( grid );
        dfs( grid, x, y );
        return cnt_path;
    }
};
