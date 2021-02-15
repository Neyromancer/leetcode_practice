// space O( 1 )
// time O( N^2 )

#include <algorithm>
#include <vector>

int threeSumClosest( std::vector<int> &nums, int target ) {
  std::sort( std::begin( nums ), std::end( nums ) );
  long int res = INT_MAX;
  for( int i = 0; i < nums.size(); ++i ) {
    int l = i + 1;
    int r = nums.size() - 1;
    while( l < r ) {
      int sum = nums[ i ] + nums[ l ] + nums[ r ];
      res = ( std::abs( target - res ) > std::abs( target - sum ) ) ? sum : res;
      if( sum > target )
        --res;
      else if( sum < target )
        ++l;
      else
        return sum;
    }
  }

  return res;
}
