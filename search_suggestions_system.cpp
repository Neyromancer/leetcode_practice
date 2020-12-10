#include <string>
#include <vector>

std::vector<std::vector<std::string>> suggestedProducts( std::vector<std::string> &products,
                                                         std::string searchWord ) {
  std::vector<std::vector<std::string>> storage;
  std::sort( std::begin( el ), std::end( el ) );
  for( int i = 0; i < searchWord.size(); ++i ) {
    if( !i ) {
      storage.push_back( find_search_words( searchWord[ i ], i, products ) );
    } else {
      storage.push_back( find_search_words( searchWord[ i ], i, storage[ i - 1 ] ) );
    }
  }

  for( auto &el : storage ) {
    while( el.size() > 3 )
      el.pop_back();
  }

  return storage;
}

std::vector<std::string> find_search_words( char ch, int index, 
                                            const std::vector<std::string> &origin ) {
  std::vector<std::string> res;
  for( const auto &el : origin ) {
    if( el[ index ] == ch )
      res.push_back( el );
  }

  return res;
}
