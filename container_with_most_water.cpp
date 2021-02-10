#include <vector>

int maxArea( std::vector<int> &height ) {
  int l = 0;
  int r = height.size() - 1;
  int max_area = 0;

  while( l < r ) {
    auto tmp = std::min( height[ l ], height[ r ] ) * ( r - l );
    max_area = std::max( max_area, tmp );

    if( l < r && height[ l ] <= height[ r ] ) {
      ++l;
    } else if( l < r && height[ l ] > height[ r ] ) {
      --r;
    }
  }

  return max_area;
}
