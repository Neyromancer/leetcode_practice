#include <vector>
#include <string>

std::vector<int> partitionLabels( std::string S ) {
  int l{ 0 };
  char ch = S[ l ];
  int r = S.size() - 1;
  std::vector<int> res;
  while( true ) {
    while( r > l && ch != S[ r ] )
      --r;

    int li = l + 1;
    std::vector<int> st( 27 );
    st[ S[ l ] - 'a' ] = r;
    while( li < r ) {
      while( li < r && ( S[ li - 1 ] == S[ li ] || st[ S[ li ] - 'a' ] != 0 ) )
        ++li;

      if( li == r )
        break;
      
      int ri = S.size() - 1;
      while( ri > r && S[ li ] != S[ ri ] )
        --ri;

      if( ri > r && S[ li ] == S[ ri ] ) {
        r = ri;
        st[ S[ li ] - 'a' ] = ri;
      } else if( ri == r ) {
        st[ S[ li ] - 'a' ] = -1;
      }

      ++li;
    }

    res.push_back( r - l + 1 );
    if( r == ( S.size() - 1 ) )
      break;

    l = r + 1;
    r = S.size() - 1;
    ch = S[ l ];
  }
  
  return res;
} 
