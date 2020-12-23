#include <algorithm>
#include <string>

int nextGreaterElement( int n ) {
  auto num = std::to_string( n );
  int i = num.size() - 1;
  for( ; i > 0; --i ) {
    if( num[ i ] > num[ i - 1 ] ) {
      reorder( num, i - 1 );
      break;
    }
  }

  if( i <= 0 )
    return -1;

  auto res = std::stoll( num );
  return ( res >= INT_MAX ? -1 : INT_MAX );
}

void reorder( std::string &num, int index ) {
  for( int i = num.size() - 1; i > index; --i ) {
    if( num[ i ] > num[ index ] ) {
      std::swap( num[ index ], num[ i ] );
      break;
    }
  }
  ++index;
  std::reverse( std::begin( num ) + index, std::end( num ) );
}
