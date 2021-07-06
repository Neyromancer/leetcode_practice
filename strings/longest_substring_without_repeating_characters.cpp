class Solution {
public:
    int lengthOfLongestSubstring( string s )
    {
        if( s.size() <= 1 )
            return s.size();
        
        std::array<int, 256> alph;
        alph.fill( -1 );
        int len{ 0 }; // 2
        int j{ 0 }; // 2
        int i{ 0 };
        for(; i < s.size(); ++i ) { // 3
            if( alph[ s[ i ] - ' ' ] >= 0 ) {
                len = std::max( len, i - j );
                j = std::max( j, alph[ s[ i ] - ' ' ] + 1 );
            }
            alph[ s[ i ] - ' ' ] = i;
        }
 
        len = std::max( len, i - j );
        
        return len;
    }
};
