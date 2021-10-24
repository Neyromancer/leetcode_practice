class Solution {
public:
    // space O( sizeof( s ) )
    // time O( sizeof( s ) )
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        if( s.empty() || k <= 0 )
            return 0;
        
        int len{ 0 };
        std::unordered_map<char, int> st;
        int l{ 0 };
        int r{ 0 };
        while( r < s.size() ) {
            ++st[ s[ r ] ];
            // time O( num of value )
            while( l < r && st.size() > k ) {
                --st[ s[ l ] ]; // O( 1 )
                if( !st[ s[ l ] ] ) // O( 1 )
                    st.erase( s[ l ] ); // O( 1 )
                ++l;
            }
            
            len = std::max( len, r - l + 1 ); // O( 1 )
            ++r;
        }
        
        return len;
    }
};

class Solution {
public:
    // space O( 1 )
    // time O( sizeof( s ) )
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        if( s.empty() || k <= 0 )
            return 0;
        
        int distinct{ 0 };
        int l{ 0 };
        int r{ 0 };
        std::array<int, 256> st{};
        int len{ 0 };
        while( r < s.size() ) {
            if( !st[ s[ r ] ] )
                ++distinct;

            ++st[ s[ r ] ];
            while( l < r && distinct > k ) {
                if( --st[ s[ l ] ] == 0 )
                    --distinct;

                ++l;
            }
            
            len = std::max( len, r - l + 1 );
            ++r;
        }
        
        return len;
    }
};
