class Solution {
public:
    // time O( 2^N ), where N == s.size
    // space O( N ), where N == s.size
    int longestPalindromeSubseq(string s)
    {
        return longestPalindromeSubseq( s, 0, s.size() - 1 );
    }
    
    int longestPalindromeSubseq( std::string_view s, int l, int r )
    {
        if( l > r )
            return 0;
        
        if( l == r )
            return 1;
        
        if( s[ l ] == s[ r ] )
            return 2 + longestPalindromeSubseq( s, l + 1, r - 1 );
        
        auto left = longestPalindromeSubseq( s, l + 1, r );
        auto right = longestPalindromeSubseq( s, l, r - 1 );
        
        return std::max( left, right );
    }
};

class Solution {
public:
    // space O( N^2 + N ), where N == s.size
    // time O( 2^N ), where N == s.size
    int longestPalindromeSubseq(string s)
    {
        std::vector<std::vector<int>> dp( s.size(), std::vector<int>( s.size() ) );
        return longestPalindromeSubseq( s, dp, 0, s.size() - 1 );
    }
    
    int longestPalindromeSubseq( std::string_view s, std::vector<std::vector<int>> &dp, int l, int r )
    {
        if( l > r )
            return 0;
        
        if( l == r )
            return 1;
        
        if( !dp[ l ][ r ] ) {
            if( s[ l ] == s[ r ] ) {
                dp[ l ][ r ] = 2 + longestPalindromeSubseq( s, dp, l + 1, r - 1 );
            } else {
                auto left = longestPalindromeSubseq( s, dp, l + 1, r );
                auto right = longestPalindromeSubseq( s, dp, l, r - 1 );
                dp[ l ][ r ] = std::max( left, right );
            }
        }
        
        return dp[ l ][ r ];
    }
};

class Solution {
public:
    // time O( N^2 )
    // space O( N^2 )
    int longestPalindromeSubseq( string s )
    {
        std::vector<std::vector<int>> dp( s.size(), std::vector<int>( s.size() ) );
        for( int i = 0; i < s.size(); ++i )
            dp[ i ][ i ] = 1;
        
        for( int i = s.size() - 1; i >= 0; --i ) {
            for( int j = i + 1; j < s.size(); ++j ) {
                if( s[ i ] == s[ j ] ) {
                    dp[ i ][ j ] = 2 + dp[ i + 1 ][ j - 1 ];
                } else {
                    dp[ i ][ j ] = std::max( dp[ i + 1 ][ j ], dp[ i ][ j - 1 ] );
                }
            }
        }
        
        return dp.front().back();
    }
};
