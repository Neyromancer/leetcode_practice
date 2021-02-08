#include <vector>

void sortColors( std::vector<int> &nums ) {
  int i = 0;
  int j = 0;
  int sz = nums.size() - 1;
  while( j < sz ) {
    if( nums[ j ] == 2 ) {
      std::swap( nums[ sz-- ], nums[ j ] );
    } else if( nums[ j ] == 0 ) {
      std::swap( nums[ j++ ], nums[ i++ ] );
    } else {
      ++j;
    }
  }
}
