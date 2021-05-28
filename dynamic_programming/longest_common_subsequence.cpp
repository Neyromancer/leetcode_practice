// TLE
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        return calcLCS( text1, text2, 0, 0 );
    }
    
    // space O( N + M ), where N == s1.size() and M == s2.size() )
    // time O( 2^(N + M) ), where N = s1.size(), M = s2.size()
    int calcLCS( std::string_view s1, std::string_view s2, int i, int j )
    {
        if( i >= s1.size() || j >= s2.size() )
            return 0;
        
        if( s1[ i ] == s2[ j ] )
            return calcLCS( s1, s2, i + 1, j + 1 ) + 1;
        
        int n1 = calcLCS( s1, s2, i + 1, j );
        int n2 = calcLCS( s1, s2, i, j + 1 );
        return std::max( n1, n2 );
    }
};

class Solution {
public:
    // space O( N * M ), where N == text1.size() and M == text2.size()
    // time O( 2^( N + M ) ), where N == text1.size() and M == text2.size()
    int longestCommonSubsequence(string text1, string text2)
    {
        std::vector<std::vector<int>> dp( text1.size(), std::vector<int>( text2.size() ) );
        return calcLCS( text1, text2, 0, 0, dp );
    }
    
    int calcLCS( std::string_view s1, std::string_view s2, int i, int j, 
               std::vector<std::vector<int>> &dp ) {
        if( i >= s1.size() || j >= s2.size() )
            return 0;
        
        if( dp[ i ][ j ] )
            return dp[ i ][ j ];
        
        if( s1[ i ] == s2[ j ] ) {
            dp[ i ][ j ] = calcLCS( s1, s2, i + 1, j + 1, dp ) + 1;
        } else {
            dp[ i ][ j ] = std::max( calcLCS( s1, s2, i, j + 1, dp ),
                                     calcLCS( s1, s2, i + 1, j, dp ) );
        }
        
        return dp[ i ][ j ];
        // return 0;
    }
};
