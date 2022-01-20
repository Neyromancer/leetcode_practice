class Solution {
public:
    // TC: O( mac( sizeof( nums ), sizeof( count ) ) )
    // SC: O( sizeof( count ) )
    int deleteAndEarn(vector<int>& nums)
    {
        std::vector<int> count( 10001 );
        for( int n : nums )
            ++count[ n ];
        
        int prev{ 0 };
        int use{ 0 };
        int avoid{ 0 };
        for( int n = 0; n < count.size(); ++n ) {
            if( !count[ n ] )
                continue;
            
            int val = std::max( use, avoid );
            if( prev == n - 1 ) {
                use = n * count[ n ] + avoid;
                avoid = val;
            } else {
                use = n * count[ n ] + val;
                avoid = val;
            }

            prev = n;
        }
        
        return std::max( use, avoid );
    }
};
