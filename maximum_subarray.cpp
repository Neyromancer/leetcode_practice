#include <vector>

// space O( 1 )
// time O( N )
int maxSubArray( std::vector<int> &nums ) {
  if( nums.size() == 1 )
    return nums.front();

  int cur = 0;
  int res = INT_MIN;
  for( int i = 0; i < nums.size(); ++i ) {
    cur += nums[ i ];

    if( nums[ i ] > cur )
      cur = nums[ i ];

    res = std::max( res, cur );
  }

  return res;
}
