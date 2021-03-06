#include <vector>

<<<<<<< HEAD
// Brute force solution
// time complexity O( N^2 )
// space complexity O( 1 )
int maxArea( std::vector<int> &height ) {
  std::size_t volume = 0;
  int size = height.size();
  for( int l = 0; l < height.size(); ++l ) {
    for( int r = size - 1; r > l; --r ) {
      std::size_t tmp_volume = std::min( height[ l ], height[ r ] ) * ( r - l );
      volume = std::max( tmp_volume, volume );
    }
  }

  return volume;
}

// Time complexity O( N )
// Space complexity O( 1 )
int maxArea( std::vector<int> &height ) {
  std::size_t volume = 0;
  int l = 0;
  int r = height.size() - 1;
  while( l < r ) {
    std::size_t tmp_volume = std::min( height[ l ], height[ r ] ) * ( r - l );
    volume = std::max( volume, tmp_volume );

    if( l < r && height[ l ] > height[ r ] )
      --r;
    else if( l < r && height[ r ] >= height[ l ] )
      ++l;
  }

  return volume;
=======
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
>>>>>>> 37a8784480b0ab7c434ed6940d0e6bc57115deef
}
