class Solution {
    std::vector<std::vector<int>> storage;
public:
    int numIslands(const vector<vector<char>>& grid)
    {
        storage.resize( grid.size() );
        for( auto &vc : storage )
            vc.resize( grid.front().size() );

        int cnt{ 0 };
        for( int i = 0; i < grid.size(); ++i ) {
          for( int j = 0; j < grid[ i ].size(); ++j ) {
           if( grid[ i ][ j ] == '1' && storage[ i ][ j ] != 1 ) {
             walk( grid, i, j );
             ++cnt;
           }
          }
       }

       return cnt;
    }

    void walk( const std::vector<std::vector<char>> &space, int i, int j )
    {
      if( i < 0 || j < 0 || i >= space.size() || j >= space[ 0 ].size() )
        return;

      if( space[ i ][ j ] == '1' && storage[ i ][ j ] == 1 )
        return;

      if( space[ i ][ j ] == '0' )
        return;

      if( space[ i ][ j ] == '1' && storage[ i ][ j ] == 0 )
        storage[ i ][ j ] = 1;

      walk( space, i + 1 , j );
      walk( space, i - 1 , j );
      walk( space, i, j + 1 );
      walk( space, i, j - 1 );
   }
};
