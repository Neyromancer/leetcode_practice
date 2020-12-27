#include <vector>

bool canJump( std::vector<int> &nums ) {
  if( nums.size() > 1 && nums[ 0 ] == 0 )
    return false;

  int nums.size() - 1;
  while( i > 0 ) {
    int steps{ 1 };
    bool is_found{ false };
    for( int j = i - 1; j >= 0; --j ) {
      if( nums[ j ] >= steps ) {
        i = j;
        is_found = true;
      }

      ++steps;
    }
    if( !is_found )
      return false;
  }

  return true;
}
