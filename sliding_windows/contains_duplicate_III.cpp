class Solution {
public:
    // time O( N log N ), where N is the size of nums
    // space O( N ), where N is the size of nums
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        std::set<std::int64_t> st;
        for( std::size_t i = 0; i < nums.size(); ++i ) {
            auto it = st.lower_bound( nums[ i ] ); // 9 // O( log( sizeof( st ) ) )
            if( it != std::end( st ) && *it <= nums[ i ] + t )
                return true;
            
            if( !st.empty() ) {
                auto jt = std::prev( it );
                if( jt == it )
                    jt = std::end( st );

                if( jt != std::end( st ) && nums[ i ] <= *jt + t )
                    return true;
            }
            
            st.insert( nums[ i ] ); // O( log( sizeof( st ) ) )
            if( st.size() > k )
                st.erase( nums[ i - k ] ); // O( log( sizeof( st ) ) )
        }
        
        return false;
    }
};

/*
[1,2,3,1]
3
0
[1,0,1,1]
1
2
[1,5,9,1,5,9] 
2
3
[2147483647,-1,2147483647]
1
2147483647
[2,0,-2,2]
2
1
*/

class Solution {
public:
    std::int64_t get_index( int n, int w )
    {
        return n < 0 ? ( n + 1 ) / w - 1 : n / w;
    }
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        if( t < 0 || k < 0 )
            return false;
        
        std::unordered_map<std::int64_t, int> st;
        std::int64_t w = (std::int64_t)t + 1;
        for( int i = 0; i < nums.size(); ++i ) {
            auto index = get_index( nums[ i ], w );
            
            if( st.count( index ) )
                return true;
            
            if( st.count( index - 1 ) && std::abs( static_cast<std::int64_t>( nums[ i ] ) - static_cast<std::int64_t>( st[ index - 1 ] ) ) < w )
                return true;
            
            if( st.count( index + 1 ) && std::abs( static_cast<std::int64_t>( nums[ i ] ) - static_cast<std::int64_t>( st[ index + 1 ] ) ) < w )
                return true;
            
            st[ index ] = nums[ i ];
            if( i >= k )
                st.erase( get_index(nums[ i - k ], w ) );
        }
        
        return false;
    }
};
