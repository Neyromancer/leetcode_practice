// time complexity O( long( n ) )
// space complexity O( 1 )

#include <vector>

int peakIndexInMountainArray( std::vector<int> &arr ) {
  int l = 0;
  int r = arr.size() - 1;
  while( l < r ) {
    int mid = l + ( ( r - l ) / 2 );
    
    if( arr[ mid ] < arr[ mid + 1 ] )
      l = mid + 1;
    else
      r = mid;
  }

  return l;
}
