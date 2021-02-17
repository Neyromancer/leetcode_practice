#include <array>
#include <cmath>
#include <string>

// space O( 1 )
// time O( N )
int characterReplacement( std::string s, int k ) {
  if( s.empty() )
    return 0;

  int start{ 0 };
  int max_repeating_chars{ 0 };
  std::array<int, 26> storage{};
  for( int end = 0; end < s.size(); ++end ) {
    max_repeating_chars = std::max( max_repeating_chars, ++storage[ s[ end ] - 'A' ] );
    if( end - start + 1 - max_repeating_chars > k ) {
      --storage[ s[ end-- ] - 'A' ];
    }

    res = std::max( res, end - start + 1 );
  }

  return res;
}
