#include <string>
#include <map>

std::map<std::string, int> storage;

bool is_valid_char( std::string ch ) {
  if( ch.empty() )
    return false;

  if( ch[ 0 ] == '0' )
    return false;

  int res{ 0 };
   try {
      res = std::stoi( ch );
   } catch( ... ) {
     return false;
   }

   if( res < 1 || res > 26 )
     return false;
  return true;
}

int numDecodings( std::string s ) {
  if( s.empty() )
    return 0;

  if( storage.find( s ) != std::end( storage ) )
    return storage[ s ];

  int res1{ 0 };
  if( s.size() >= 1 && is_valid_char( s.substr( 0, 1 ) ) )
    res1 = decode( ( ( s.size() > 1 ) ? s.substr( 1 ) : "" ) );

  int res2{ 0 };
  if( s.size() >= 2 && is_valid_char( s.substr( 0, 2 ) ) )
    res2 = decode( ( ( s.size() > 2 ) ? s.substr( 2 ) : "" ) );

  storage[ s ] = res1 + res2;
  return storage[ s ];
}

