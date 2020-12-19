#include <string>

int numberOfSubstrings( std::string s ) {
  int cnt{ 0 };
  int prev{ 0 };
  int arr[ 3 ]{};
  for( int i = 0; i < s.size(); ++i ) {
    ++arr[ s[ i ] - 'a' ];
    if( arr[ 0 ] && arr[ 1 ] && arr[ 2 ] ) {
      while( prev < i && arr[ 0 ] && arr[ 1 ] && arr[ 2 ] ) {
        --arr[ s[ prev ] - 'a' ];
        cnt += s.size() - i;
        ++prev;
      }
    }
  }

  return cnt;
}
