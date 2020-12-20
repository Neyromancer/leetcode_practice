#include <vector>

int heightChecker( std::vector<int> &heights ) {
  std::vector<int> storage( 101 );
  for( auto h : heights )
    ++storage[ h ];

  int cur_height{ 0 };
  int cnt{ 0 };
  for( int i = 0; i < heights.size(); ++i ) {
    while( storage[ cur_height ] == 0 )
      ++cur_height;

    if( cur_height != heights[ i ] )
      ++cnt;

    --storage[ cur_height ];
  }

  return cnt;
}
