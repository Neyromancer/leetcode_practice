#include <algorithm>
#include <string>

std::string getSmallestString( int n, int k ) {
  std::string res;
  while( n && k ) {
    --n;
    auto val = k - n;
    if( val <= static_cast<int>( 'z' - 'a' + 1 ) ) {
      res += static_cast<char>( ( val - 1 ) + 'a' );
      k -= val;
    } else {
      res += 'z';
      k -= static_cast<int>( 'z' - 'a' + 1 );
    }
  }

  std::reverse( std::begin( res ), std::end( res ) );
  return res;
}
