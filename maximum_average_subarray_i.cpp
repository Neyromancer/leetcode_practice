#include <vector>

double findMaxAverage( std::vector<int> &nums, int k ) {
  double sum = std::accumulate( std::begin( nums ), std::next( std::begin( nums ), k ), 0 );
  double res = ( sum * 1.0 ) / k;
  for( int i = 0; i < nums.size() - k; ++i ) {
    sum = sum - nums[ i ] + nums[ i + k ];
    double avr = sum / ( k * 1.0 );
    res = std::fmax( avr, res );
  }

  return res;
}
