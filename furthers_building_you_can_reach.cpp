#include <vector>


// Space O( N )
// Time O( log N * Nlog N )
int furthestBuilding( std::vector<int> &heights, int bricks, int ladders )
{
  int l{ 0 };
  int r = heights.size() - 1;
  int res{ 0 };
  while( l <= r ) {
    int mid = l + ( r - l ) / 2;
    auto diff = get_sorted_diff( heights, mid );
    if( can_move_futher( std::move( diff ), bricks, ladders ) ) {
      res = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return res;
}

std::vector<int> get_sorted_diff( const std::vector<int> &heights, int r )
{
  std::vector<int> res( r );
  for( int i = 0; i <= r; ++i )
    res[ i - 1 ] = heights[ i ] - heights[ i - 1 ];

  std::sort( std::begin( res ), std::end( res ) );
  return res;
}

bool can_move_further( std::vector<int> &&heights, int bricks, int ladders )
{
  for( auto h : heights ) {
    if( h <= 0 )
      continue;

    if( bricks >= h ) {
      bricks -= h;
    } else if( ladder > 0 ) {
      --ladder;
    } else {
      return false;
    }
  }

  return true;
}
