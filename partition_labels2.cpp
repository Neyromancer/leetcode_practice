#include <vector>
#include <string>

std::vector<int> partitionLabels( std::string S ) {
  std::vector<int> last( 26 );
  for( int i = 0; i < S.size(); ++i )
    last( S[ i ] - 'a' ) = i;

  std::vector<int> res;
  int j = 0;
  int anchor = 0;
  for( int i = 0; i < S.size(); ++i ) {
    j = std::mac( j, last[ S[ i ] - 'a' ] );
    if( j == i ) {
      res.push_back( i - anchor + 1 );
      ahcnor = i + 1;
    }
  }

  return res;
}
