#include <array>
#include <string>

bool closeStrings( std::string &word1, std::string &word2 ) {
  if( word1.size() != word2.size() )
    return false;

  std::array<int, 26> alph1{};
  std::array<int, 26> alph2{};
  for( int i = 0; i < word1.size(); ++i ) {
    ++alph1[ word1[ i ] - 'a' ];
    ++alph2[ word2[ i ] - 'a' ];
  }

  int res{ 0 };
  for( int i = 0; i < 26; ++i ) {
    if( ( !alph1[ i ] && alph2[ i ] ) || ( alph1[ i ] && !alph2[ i ] ) )
      return false;

    if( alph1[ i ] )
      res = res ^ alph1[ i ];
  
    if( alph2[ i ] )
      res = res ^ alph2[ i ];
  }

  return res == 0;
}
