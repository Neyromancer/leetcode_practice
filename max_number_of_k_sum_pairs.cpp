#include <cmath>
#include <vector>
#include <unordered_map>

int maxOperations( std::vector<int> &nums, int K ) {
  std::unordered_map<int, int> storage;
  for( auto n : nums )
    if( n < K )
      ++storage[ n ];

  int res = 0;
  for( auto [ n, cnt ] : storage ) {
    if( storage.count( K - n ) )
      res += std::min( storage[ K - n ], cnt );
  }

  return res / 2;
}
