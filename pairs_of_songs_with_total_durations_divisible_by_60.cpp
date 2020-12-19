#include <cstdlib>
#include <vector>

int numPairDivisibleBy60( std::vector<int> &time ) {
  int cnt{ 0 };
  std::vector<int> storage( 60 );
  for( auto t : time ) {
    if( t % 60 == 0 ) {
      cnt += storage[ 0 ];
    } else {
      cnt += storage[ 60 - t % 60 ];
    }

    ++storage[ t % 60 ];
  }

  return cnt;
}
