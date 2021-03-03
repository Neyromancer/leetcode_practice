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

// ==================================================
// space O( N )
// time O( N log N )


#include <vector>
#include <priority_queue>
int furthestBuilding( std::vector<int> heights, int bricks, int ladders )
{
  std::priority_queue<int> used_bricks;
  for( int i = 0; i < heights.size() - 1; ++i ) {
    int height_diff = heights[ i + 1 ] - heights[ i ];
    if( height_diff <= 0 )
      continue;

    if( bricks >= height_diff ) {
      bricks -= height_diff;
      used_bricks.push( height_diff );
    } else if( ladders ) {
      if( !used_bricks.empty() && used_bricks.top() > height_diff ) {
        int rec_bricks = used_bricks.top();
        used_bricks.pop();
        bricks += rec_bricks;
        bricks -= height_diff;
        --ladders;
        used_bricks.push( height_diff );
      }
    } else 
      return i;
  }

  return heights.size() - 1;
}
