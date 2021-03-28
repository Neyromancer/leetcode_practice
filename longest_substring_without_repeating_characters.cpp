/***
"abcabcbb"
"bbbbb"
"pwwkew"
""
"abc"
"a"
"aca"
"abbbcabdd"
"abbbcabd"
"abcd"
"abcccadebgrat"
*/

// space O( 1 )
// time O( N ), N - s.size()
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int length{ 0 };
        std::array<int, 128> alph{};
        int j{ 0 };
        int i{ 0 };
        for( ; i < s.size(); ++i ) {
            if( alph[ s[ i ] - ' ' ] ) {
                if( j > alph[ s[ i ] - ' ' ] ) {
                    alph[ s[ i ] - ' ' ] = i + 1;
                    continue;
                }
                
                length = std::max( length, i - j );
                j = alph[ s[ i ] - ' ' ];
            }

            alph[ s[ i ] - ' ' ] = i + 1;
        }
        
        length = std::max( length, i - j );
        return length;        
    }
};
