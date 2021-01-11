#include <iostream>
#include <string>
#include <vector>


int minCost( const std::string &s, std::vector<int> &cost ) {
  int sum{ 0 };
  int i = 0;
  while( i + 1 < s.size() ) {
    int max_val{ cost[ i ] };
    int letter = s[ i ] - 'a';
    sum += cost[ i ];
    while( i + 1 < s.size() &&
           letter == static_cast<int>( ss[ i + 1 ] - 'a' ) ) {
      max_val = std::max( max_val, cost[ ++i ] );
      sum += cost[ i ];
    }

    sum -= max_val;
    ++i;
  }

  return sum;
}
