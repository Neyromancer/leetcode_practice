#include <vector>

bool canPlaceFlowers( std::vector<int> &flowerbed, int n ) {
  if( flowerbed.size() == 1 ) {
    if( !flowerbed[ 0 ] || !n )
      return true;
    return false;
  }

  int i = 0;
  int sz = flowerbed.size();
  while( i < sz ) {
    if( !flowerbed[ i ] ) {
      if( ( i == 0 && i + 1 < sz && !flowerbed[ i + 1 ] ) ||
          ( i == sz - 1 && i - 1 >= 0 && !flowerbed[ i - 1 ] ) ) {
        --n;
        i += 2;
        continue;
      }

      if( i + 1 < sz && !flowerbed[ i + 1 ] && i - 1 >= 0 && !flowerbed[ i - 1 ] ) {
        --n;
        i += 2;
        continue;
      }
    }
    if( n <= 0 )
      return true;

    ++i;
  }

  return ( n <= 0 );
}

// O( N ), N = flowerbed.size();
// O( 1 )
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int i = 0;
        int fsize = flowerbed.size();
        while( i < fsize ) {
            if( flowerbed[ i ] == 0 ) {
                if( i - 1 >= 0 && flowerbed[ i - 1 ] == 1 ) {
                    ++i;
                    continue;
                } else if( i + 1 < fsize && flowerbed[ i + 1 ] == 1 ) {
                    ++i;
                    continue;
                }
                
                i += 2;
                --n;
            } else
                i += 2;
            
            if( n <= 0 )
                return true;
        }
        
        // std::cout << "n = " << n << std::endl;
        return n <= 0;
    }
};
