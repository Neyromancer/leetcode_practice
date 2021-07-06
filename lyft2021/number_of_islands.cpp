class Solution {
public:
    // time O( N^2 * M^2 ), where N == grid.size and M == grid.front.size
    // space O( N * M ), where N == grid.size and M == grid.front.size 
    int numIslands(vector<vector<char>>& grid)
    {
        std::vector<std::vector<bool>> st( grid.size(), 
                                          std::vector<bool>( grid.front().size() ) );
        int islands{ 0 };
        for( int i = 0; i < grid.size(); ++i ) {
            for( int j = 0; j < grid.front().size(); ++j ) {
                if( !st[ i ][ j ] && grid[ i ][ j ] == '1' ) {
                    dfs( st, grid, i, j );
                    ++islands;
                }
            }
        }
        
        return islands;
    }
    
    void dfs( std::vector<std::vector<bool>> &st, const vector<vector<char>> &grid,
            int i, int j )
    {
        if( i >= grid.size() || j >= grid.front().size() || i < 0 || j < 0 )
            return;
        
        if( st[ i ][ j ] || grid[ i ][ j ] == '0' )
            return;
        
        st[ i ][ j ] = true;
        dfs( st, grid, i + 1, j );
        dfs( st, grid, i - 1, j );
        dfs( st, grid, i, j + 1 );
        dfs( st, grid, i, j - 1 );
    }
};
