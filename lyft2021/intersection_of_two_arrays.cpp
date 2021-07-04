ass Solution {
public:
    // time O( N ), where N is the size of the longes sequence of nums
    // space O( 1 )
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        std::array<int, 1001> st;
        st.fill( -1 ); // O( sizeof( st ) )
        for( int n : nums1 )
            st[ n ] = 1; // O( 1 )
        
        for( int n : nums2 ) {
            if( st[ n ] > 0 )
                st[ n ] -= 1; // O( 1 )
        }
        
        std::vector<int> res;
        for( std::size_t i = 0; i < st.size(); ++i ) {
            if( !st[ i ] )
                res.push_back( i ); // O( 1 )
        }
        
        return res;
    }
};
