#include <cstdlib>
#include <iostream>
#include <vector>

int maxProfit( const std::vector<int> &prices ) {
  if( prices.size() <= 1 )
    return 0;

  int sz = prices.size() - 1;
  int i = 0;
  int max_profit = 0;

  while( i < sz ) {
    while( i < sz && prices[ i ] >= prices[ i + 1 ] )
      ++i;

    int valley = prices[ i ];

    while( i < sz && prices[ i ] <= prices[ i + 1 ] )
      ++i;

    int peak = prices[ i ];
    max_profit += peak - valley;
  }

  return max_profit;
}

int main( void ) {
  std::vector<std::vector<int>> tests {
    {1},
    {7,1,5,3,6,4},
    {1,1,1,1,1},
    {3,2,1},
    {1,2,3}
  };

  for( const auto &el : tests )
    std::cout << maxProfit( el ) << std::endl;

  return EXIT_SUCCESS;
}
