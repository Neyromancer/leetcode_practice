#include <string>

int lengthOfLastWord( std::string s ) {
  if( s.empty() )
    return 0;

  int cnt{ 0 };
  for( int i = s.size() - 1; i >= 0; --i ) {
    if( s[ i ] == ' ' && cnt )
      return cnt;

    if( s[ i ] != ' ' )
      ++cnt;
  }

  return cnt;
}
