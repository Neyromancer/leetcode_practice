#include <algorithm>
#include <vector>


// time complexity O( NlogN )
// space complexity O( 1 )
std::size_t sum_divided( const std::vector<int> &nums, int divisor )
{
  int res{ 0 };
  std::for_each( std::begin( nums ), std::end( nums ), [ &res, divisor ]( int num ){
    res += static_cast<int>( std::ceil( ( ( nums * 1.0 ) / divisor ) ) );
  } );

  return res;
}

int smallestDivisor( std::vector<int> &nums, int threshold )
{
  std::sort( std::begin( nums ), std::end( nums ) );

  int l{ 1 };
  int r{ nums.back() };
  int res{ INT_MAX };
  while( l <= r ) {
    int divisor = l + ( r - l ) / 2;
    std::size_t sum = sum_divided( nums, divisor );
    if( sum > threshold ) {
      l = divisor + 1;
    } else if( sum <= threshold ) {
      r = divisor - 1;
      res = std::min( res, divisor );
    }
  }

  return res;
}
