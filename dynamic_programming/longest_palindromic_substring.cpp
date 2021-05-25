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
