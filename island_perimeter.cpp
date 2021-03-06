#include <vector>

// space O( row x column )
// time O( row x column )
class Solution {
    std::vector<std::vector<int>> storage;
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        storage.resize( grid.size() );
        for( auto &el : storage )
            el.resize( grid.front().size() );
        
        int perimeter{ 0 };
        for( int i = 0; i < grid.size(); ++i ) {
            for( int j = 0; j < grid[ i ].size(); ++j ) {
                if( grid[ i ][ j ] == 1 && storage[ i ][ j ] == 0 ) {
                    perimeter = count_perimeter( grid, i, j );
                }
            }
        }
        
        return perimeter;
    }
    
    int count_perimeter( const vector<vector<int>>& grid, int i, int j )
    {
        if( i < 0 || j < 0 || i >= grid.size() || j >= grid.front().size() )
            return 0;
        
        if( grid[ i ][ j ] == 0 )
            return 0;
        
        if( grid[ i ][ j ] == 1 && storage[ i ][ j ] == 1 )
            return 0;
        
        storage[ i ][ j ] = 1;
        int p{ 0 };
        if( i == 0 || ( i > 0 && grid[ i - 1 ][ j ] == 0 ) )
            ++p;
           
        if( i == grid.size() - 1 || ( i < grid.size() - 1 && grid[ i + 1 ][ j ] == 0 ) )
            ++p;
           
        if( j == 0 || ( j > 0 && grid[ i ][ j - 1 ] == 0 ) )
            ++p;
           
        if( j == grid[ 0 ].size() - 1 || ( j < grid[ 0 ].size() - 1 && grid[ i ][ j + 1 ] == 0 ) )
            ++p;
           
           return p + count_perimeter( grid, i + 1, j ) +
                  count_perimeter( grid, i - 1, j ) +
                  count_perimeter( grid, i, j + 1 ) +
                  count_perimeter( grid, i, j - 1 );
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////

// space O( row x column )
// time O( row x column )
int islandPerimeter( const std::vector<std::vector<int>> &grid )
{
  int row = grid.size();
  int column = grid[ 0 ].size();
  int left = 0;
  int right = 0;
  int up = 0;
  int down = 0;
  int perimeter = 0;
  for( int i = 0; i < row; ++i ) {
    for( int j = 0; j < column; ++j ) {
      if( grid[ i ][ j ] == 0 )
        continue;

      if( i == 0 ) up = 0;
      else up = grid[ i ][ j ];

      if( i == row - 1 ) down = 0;
      else down = grid[ i ][ j ];

      if( j == 0 ) left = 0;
      else left = grid[ i ][ j ];

      if( j == column - 1 ) right = 0;
      else right = grid[ i ][ j ];

      perimeter += 4 - ( up + down + left + right );
    }
  }

  return perimeter;
}
