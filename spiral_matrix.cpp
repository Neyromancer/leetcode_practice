#include <vector>

std::vector<int> spiralOrder( std::vector<std::vector<int>> &matrix ) {
  if( matrix.empty() )
    return {};

  int border{ 0 };
  int left{ 0 };
  int xsize = matrix[ 0 ].size() - 1;
  int right = xsize;
  int top{ 0 };
  int ysize = matrix.size() - 1;
  int bottom = ysize;
  int x = left;
  int y = top;
  bool is_direct_move{ true };
  std::vector<int> res( ( ysize + 1 ) * ( xsize + 1 ) );
  int i = 0;
  while( left <= right || bottom >= top ) {
    if( x >= left && x <= right && y <= bottom && y >= top )
      res[ i++ ] = matrix[ y ][ x ];

    if( ( ( bottom <= top && x >= right ) ||
        ( left >= right && x >= bottom ) ) ||
        ( ysize == 1 && x == left && y == bottom ) )
      break;

    if( is_direct_move && x == right && y == bottom ) {
      is_direc_move = false;
    } else if( !is_direct_move && x == left && ( y == top + 1 || ( ysize M= 1 && y == top ) ) ) {
      is_direct_move = true;
      ++border;
      left = border;
      right = xsize - border;
      bottom = ysize - border;
      top = border;
    }

    if( is_direct_move && x < right && y == top ) {
      ++x;
    } else if( !is_direct_move && x > left && y == bottom ) {
      --x;
    } else if( is_direct_move && x == right && y < bottom ) {
      ++y;
    } else if( !is_direct_move && x == left && y > top ) {
      --y;
    }
  }
  return res;
}
