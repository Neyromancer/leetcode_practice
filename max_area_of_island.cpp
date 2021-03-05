#include <vector>

// time O( N x M )
// space O( N x M )
class Solution {
    std::vector<std::vector<int>> storage;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        if( grid.empty() || grid.front().empty() )
            return 0;
        
        int area{ 0 };
        init( storage, grid );
        
        for( int i = 0; i < grid.size(); ++i ) {
            for( int j = 0; j < grid[ i ].size(); ++j ) {
                if( grid[ i ][ j ] == 1 && storage[ i ][ j ] == 0 ) {
                    int cnt{ 0 };
                    count_area( grid, i, j, cnt );
                    area = std::max( area, cnt );
                }
            }
        }
        
        return area;
    }
    
    void count_area( const std::vector<std::vector<int>> &grid, int i, int j, int &cnt )
    {
        if( i < 0 || j < 0 || i >= grid.size() || j >= grid[ 0 ].size() )
            return;
        
        if( grid[ i ][ j ] == 0 )
            return;
        
        if( grid[ i ][ j ] == 1 && storage[ i ][ j ] == 1 )
            return;
        
        ++cnt;
        storage[ i ][ j ] = 1;
        count_area( grid, i, j + 1, cnt );
        count_area( grid, i, j - 1, cnt );
        count_area( grid, i + 1, j, cnt );
        count_area( grid, i - 1, j, cnt );
    }
    
    void init( std::vector<std::vector<int>> &vc1, 
               const std::vector<std::vector<int>> &grid )
    {
        vc1.resize( grid.size() );
        for( auto &el : vc1 )
            el.resize( grid[ 0 ].size() );
    }
};
