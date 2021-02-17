#include <algorithm>
#include <vector>
#include <set>

// space O( N )
// time O( N^3 )
std::vector<std::vector<int>> fourSum( std::vector<int> &nums, int target ) {
  std::sort( std::begin( nums ), std::end( nums ) );
  std::set<std::vector<int>> storage;
  for( int i = 0; i < nums.size(); ++i ) {
    for( int j = j + 1; j < nums.size(); ++j ) {
      int l = j + 1;
      int r = nums.size() - 1;
      auto sum = nums[ i ]  + nums[ j ];
      while( l < r ) {
        auto s = sum + nums[ l ] + nums[ r ];
        if( s > target ) {
          --r;
        } else if( s < target ) {
          ++l;
        } else {
          std::vector<int> tmp{ nums[ i ], nums[ j ], nums[ l ], nums[ r ] };
          ++l;
          while( l < r && tmp[ 2 ] == nums[ l ] )
            ++l;

          --r;
          while( l < r && tmp[ 3 ] == nums[ r ] )
            --r;

          storage.insert( tmp );
        }
      }
    }
  }

  std::vector<std::vector<int>> res;
  res.reserve( storage.size() );
  for( auto &&el : storage )
    res.push_back( std::move( el ) );

  return res;
}
