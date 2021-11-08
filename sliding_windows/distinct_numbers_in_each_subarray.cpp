class Solution {
public:
    // time O( sizeof( nums ) )
    // space O( sizeof( nums ) )
    vector<int> distinctNumbers(vector<int>& nums, int k)
    {
        if( k <= 0 )
            return {};
        
        if( k == 1)
            return std::vector<int>( nums.size(), 1 );
        

        std::unordered_map<int, int> st;
        std::vector<int> res;
        for( int i = 0; i < nums.size(); ++i ) {
            ++st[ nums[ i ] ];
            if( i + 1 - k >= 0 ) {
                res.push_back( st.size() );
                if( --st[ nums[ i + 1 - k ] ] == 0 )
                    st.erase( nums[ i + 1 - k ] );
            }
        }
        
        return res;
    }
};
