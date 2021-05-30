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

class Solution {
public:
    /// space O( N ), where N is the shorted string
    /// time O( N * M ), where N == text1.size() and M == text2.size()
    int longestCommonSubsequence(string text1, string text2)
    {
        if( text1.size() < text2.size() )
            return longestCommonSubsequence( text2, text1 );

        std::vector<std::vector<int>> dp( 2, std::vector<int>( text2.size() + 1 ) );
        int res{ 0 };
        for( int i = 0, row = 1; i < text1.size(); ++i, row ^= 1 ) {
            for( int j = 0; j < text2.size(); ++j ) {
                int col = j + 1;
                if( text1[ i ] == text2[ j ] )
                    dp[ row ][ col ] = 1 + dp[ row ^ 1 ][ col - 1 ];
                else
                    dp[ row ][ col ] = std::max( dp[ row ^ 1 ][ col ], dp[ row ][ col - 1 ] );
                
                res = std::max( dp[ row ][ col ], res );
            }
        }
        
        return res;
    }
};
