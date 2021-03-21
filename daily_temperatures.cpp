#include <stack>
#include <vector>

// space complexity O( N )
// time complexity O( N )
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

// space O( 1 )
// time O( N )

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        std::vector<int> res( T.size() );
        std::array<int, 101> index_storage{};
        index_storage.fill( INT_MAX );
        for( int i = T.size() - 1; i >= 0; --i ) {
            int warmer_index = INT_MAX;
            for( int j = T[ i ] + 1; j <= 100; ++j ) {
                if( index_storage[ j ] < warmer_index ) {
                    warmer_index = index_storage[ j ];
                }
            }
            if( warmer_index < INT_MAX )
                res[ i ] = warmer_index - i;
            
            index_storage[ T[ i ] ] = i;
        }
        
        return res;
    }
};

// time O( T.size() )
// space O( T.size() )
class Solution {
public:
  std::vector<int> dailyTemperatures( std::vector<int> &T )
  {
    std::vector<int> storage( T.size() );
    std::vector<int> res( T.size() );
    int top = -1;
    for( int i = 0; i < T.size(); ++i ) {
      while( top > -1 && T[ i ] > T[ storage[ top ] ] ) {
        int index = storage[ top-- ];
        res[ index ] = i - index;
      }
 
      storage[ ++top ] = i;
    }

    return res;
  }
};

// space O( T.size() )
// time O( 1 ), no additional space except for the result
class Solution {
public:
  std::vector<int> dailyTemperatures( std::vector<int> &T )
  {
    std::vector<int> res( T.size() );
    for( int i = T.size() - 1; i >= 0; --i ) {
      int j = i + 1;
      while( j < T.size() && T[ j ] <= T[ i ] ) {
        if( res[ j ] ) j += res[ j ];
	else j = T.size();
      }
  
      if( j < T.size() )
        res[ i ] = j - i;
    }

    return res;
  }
};

// space O( T.size() )
// time O( T.size() )
class Solution {
public:
  std::vector<int> dailyTemperatures( std::vector<int> &T ) 
  {
    if( T.empty() )
      return {};

    std::vector<int> res;
    std::storage<std::pair<int,int>> storage;
    storage.push( { T.back(), 0 } );
    res[ T.size() - 1 ] = 0;
    for( int i = T.size() - 2; i >= 0; --i ) {
      int cnt{ 1 };
      while( !storage.empty() && storage.top().first <= T[ i ] ) {
        cnt += storage.top().second;
        storage.pop();
      }

      if( storage.empty() ) {
        storage.push( { T[ i ], 0 } );
      } else {
        storage.push( { T[ i ], cnt } );
      }

      res[ i ] = storage.top().second;
    }

    return res;
  }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T)
    {
        int right_max{ T.back() };
        std::vector<int> res( T.size() );
        for( int i = T.size() - 1; i >= 0; --i ) {
            if( right_max <= T[ i ] ) {
                right_max = T[ i ];
                continue;
            }
            
            int days{ 1 };
            while( i + days < T.size() && T[ i ] >= T[ i + days ] )
                days += res[ i + days ];
            
            res[ i ] = days;
        }
        
        return res;
    }
};
