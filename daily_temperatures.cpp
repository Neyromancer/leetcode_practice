#include <stack>
#include <vector>

std::vector<int> dailyTemperature( std::vector<int> &T ) {
  std::stack<int> storage;
  std::vector<int> res( T.size() );
  for( int i = T.size() - 1; i >= 0; --i ) {
    while( !storage.empty() && T[ i ] >= T[ storage.top() ] )
      storage.pop();

    res[ i ] = ( storage.empty() ) ? 0 : storage.top() - i;
    storage.push( i );
  }

  return res;
}
