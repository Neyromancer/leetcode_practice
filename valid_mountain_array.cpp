#include <vector>

bool validMountain( std::vector<int> &arr ) {
  if( arr.size() < 3 )
    return false;

  int r = arr.size() - 1;
  while( r - 1 >= 0 && arr[ r - 1 ] > arr[ r ] )
    --r;

  if( r == arr.size() - 1 || !r )
    return false;

  int l = 0;
  while( l + 1 < arr.size() && arr[ l + 1 ] > arr[ l ] )
    ++l;

  if( !l || l == arr.size() - 1 )
    return false;

  if( l == r )
    return true;

  return false;
}
