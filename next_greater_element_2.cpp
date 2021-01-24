#include <stack>
#include <vector>

std::vector<int> nextGreaterElements( std::vector<int> &nums ) {
  if( nums.empty() )
    return {};

  std::stack<int> st;
  std::vector<int> res( nums.size(), -1 );
  for( int i = 2 * nums.size(); i >= 0; --i ) {
    while( !st.empty() && nums[ i % nums.size() ] >= nums[ st.top() ] )
      st.pop();

    res[ i % nums.size() ] = ( st.empty() ) ? -1 : nums[ st.top() ];
    st.push( i % nums.size() ];
  }

  return res;
}
