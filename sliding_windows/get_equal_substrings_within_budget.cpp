class Solution {
public:
    /*
    "abcd"
"bcdf"
3
"abcd"
"cdef"
3
"abcd"
"acde"
0
"aaaa"
"aaaa"
0
"aaaa"
"aaaa"
1
"zad"
"aae"
3
"zad"
"aae"
0
"zad"
"aae"
100
"abcd"
"cdef"
1
    */
    // time O( sizeof( s ) )
    // space O( 1 )
    int equalSubstring(string s, string t, int maxCost)
    {
        if( s.empty() || t.empty() )
            return 0;
        
        int l{ 0 };
        int r{ 0 };
        int len{ 0 };
        while( r < s.size() ) {
            int diff = std::abs( s[ r ] - t[ r ] );
            while( l < r && diff > maxCost ) {
                maxCost += std::abs( s[ l ] - t[ l ] );
                ++l;
            }
            
            if( diff <= maxCost )
                len = std::max( len, r - l + 1 );
            maxCost -= diff;
            ++r;
        }
        
        return len;
    }
};
