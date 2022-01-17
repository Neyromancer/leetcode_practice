class Solution {
public:
    // TC: O( n * m )
    // SC: O( 1 )
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid.front().size();
        if( obstacleGrid[ 0 ][ 0 ] || obstacleGrid[ m - 1 ][ n - 1 ] )
            return 0;
        
        for( int i = 0; i < m; ++i ) {
            for( int j = 0; j < n; ++j ) {
                if( !i && !j ) {
                    obstacleGrid[ i ][ j ] = 1;
                    continue;
                }
                
                if( obstacleGrid[ i ][ j ] == 1 ) {
                    obstacleGrid[ i ][ j ] = 0;
                    continue;
                }
                
                int top{ 0 };
                if( i - 1 >= 0 )
                    top = obstacleGrid[ i - 1 ][ j ];
                
                int left{ 0 };
                if( j - 1 >= 0 )
                    left = obstacleGrid[ i ][ j - 1 ];
                
                obstacleGrid[ i ][ j ] = left + top;
            }
        }
        return obstacleGrid[ m - 1 ][ n - 1 ];
    }
};
