class Solution {
public:
    // time O( depth of the list * size of the longest list )
    // space O( depth of the list )
    int depthSum(vector<NestedInteger>& nestedList)
    {
        std::stack<std::pair<int, NestedInteger>> st;
        int res{ 0 };
        for( const auto& lst : nestedList ) {
            st.push( std::make_pair( 1, lst ) ); // O( 1 )
            while( !st.empty() ) { // O( 1 )
                const auto [ lvl, nested_list ] = st.top();
                st.pop();
                
                if( !nested_list.isInteger() ) {
                    for( const auto& el : nested_list.getList() )
                        st.push( std::make_pair( lvl + 1, el ) ); // O( 1 )
                } else {
                    res += nested_list.getInteger() * lvl;
                }
            }
        }
        
        return res;
    }
};
