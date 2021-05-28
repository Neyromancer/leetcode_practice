class Solution {
public:
    // time O( N^2 ), where N == s.size()
    // space O( 1 ) 
    string longestPalindrome( string s )
    {
        if( s.empty() || s.size() == 1 )
            return s;
        
        int l{ 0 };
        int r{ 0 };
        for( int i = 0; i < s.size(); ++i ) {
            int len1 = expandFromCenter( s, i, i );
            int len2 = expandFromCenter( s, i, i + 1 );
            if( int len = std::max( len1, len2 ); len > r - l ) {
                l = i - ( ( len - 1 ) / 2 );
                r = i + ( len / 2 );
            }
        }

        return s.substr( l, r - l + 1 );
    }
    
    int expandFromCenter( const std::string &s, int l, int r )
    {
        if( l > r || l < 0 || r >= s.size() )
            return 0;
        
        while( l >= 0 && r < s.size() && s[ l ] == s[ r ] ) {
            --l;
            ++r;
        }
        
        return r - l - 1;
    }
};

class Solution {
public:
    // time O( N^2 ), where N == s.size()
    // space O( 1 )
    string longestPalindrome(string s)
    {
        if( s.size() <= 1 )
            return s;
        
        int l{ 0 };
        int r{ 0 };
        
        int i = 0;
        while( i < s.size() ) {
            int start = i;
            int end = i;
            
            while( end < s.size() - 1 && s[ end ] == s[ end + 1 ] ) // O( 1 )
                ++end;
            
            i = end + 1;
            while( start - 1 >= 0 && end + 1 < s.size() && s[ start - 1 ] == s[ end + 1 ] ) { // O( 1 )
                --start;
                ++end;
            }

            if( end - start > r - l ) {
                r = end;
                l = start;
            }
        }
        
        return s.substr( l, r - l + 1 );
    }
};

class Solution {
public:
    // space O( N * M ), where N == text1.size() and M == text2.size()
    // time O( N * M ), where N == text1.size() and M == text2.size()
    int longestCommonSubsequence(string text1, string text2)
    {
        std::vector<std::vector<int>> dp( text1.size() + 1, std::vector<int>( text2.size() + 1 ) );
        int res{ 0 };
        for( int i = 0; i < text1.size(); ++i ) {
            for( int j = 0; j < text2.size(); ++j ) {
                int ii = i + 1;
                int jj = j + 1;
                if( text1[ i ] == text2[ j ] )
                    dp[ ii ][ jj ] = 1 + dp[ ii - 1 ][ jj - 1 ];
                else
                    dp[ ii ][ jj ] = std::max( dp[ ii ][ jj - 1 ], dp[ ii - 1 ][ jj ] );
                
                res = std::max( dp[ ii ][ jj ], res );
            }
        }
        
        return res;
    }
};
