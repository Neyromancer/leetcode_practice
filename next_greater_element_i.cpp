#include <stack>
#include <vector>
#include <unordered_map>

std::vector<int> nextGreaterElement( std::vector<int> &nums1, std::vector<int> &nums2 ) {
  std::stack<int> st;
  std::unordered_map<int, int> storage;
  for( int i = nums2.size(); i >= 0; --i ) {
    while( !st.empty() && nums2[ i ] > st.top() )
      st.pop();

    storage[ nums2[ i ] ] = ( st.empty() ) ? -1 : st.top();
    st.push( nums2[ i ] );
  }

  std::vector<int> res( nums1.size() );
  for( int i = 0; i < nums1.size(); ++i )
    res[ i ] = storage[ nums1[ i ] ];

  return res;
}
