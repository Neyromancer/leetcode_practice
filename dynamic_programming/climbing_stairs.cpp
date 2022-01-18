// Bottom-up approach
// TC: O( n )
// SC: O( n )
class Solution {
    std::unordered_map<int, int> st;
public:
    int climbStairs(int n) {        
        if( n < 0 )
            return 0;
        
        if( !n )
            return 1;

        if( st.count( n ) )
            return st[ n ];

        st[ n ] = climbStairs( n - 1 ) + climbStairs( n - 2 );
        return st[ n ];
    }
};

class Solution {
public:
    // TC: O( n )
    // SC: O( n )
    int climbStairs(int n)
    {
        std::vector<int> storage( n + 1 );
        storage[ 0 ] = 1;
        storage[ 1 ] = 1;
        for( int i = 2; i <= n; ++i ) {
            storage[ i ] = storage[ i - 2 ] + storage[ i - 1 ];
        }
        
        return storage[ n ];
    }
};
