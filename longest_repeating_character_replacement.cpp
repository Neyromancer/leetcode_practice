#include <array>
#include <string>


// space O( 1 )
// time O( N^2 )
int characterReplacement( std::string s, int k ) {
  if( s.empyt() )
    return 0;

  int start{ 0 };
  int max_repeating_chars{ 0 };
  std::array<int, 26> alpha{};
  int res{ 0 };
  for( int end = 0; end < s.size(); ++end ) {
    max_repeating_chars = std::max( max_repeating_chars, ++alpha[ s[ end ] - 'A' ] );
    while( end - start + 1 - max_repeating_chars > k ) {
      --alpha[ s[ end ] - 'A' ];
      ++start;
    }

    res = std::max( res, end - start + 1 );
  }

  return res;
}
