#include <array>
#include <vector>

int minIncrementForUnique( std::vector<int> &A ) {
  std::array<int, 50000> st{};
  for( auto n : A )
    st[ n ]++;

  int taken = 0;
  int res = 0;
  for( int i = 0; i < st.size(); ++i ) {
    if( st[ i ] >= 2 ) {
      taken += ( st[ i ] - 1 );
      res -= i * ( st[ i ] - 1 );
    } else if( taken > 0 && st[ i ] == 0 ) {
      --taken;
      res += i;
    }
  }

  return res;
}
