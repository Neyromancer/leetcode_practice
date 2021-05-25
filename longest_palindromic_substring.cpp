// space O( N^2 ), N - string size
// time O( 1 )
class Solution {
public:
    bool is_anagram( const std::string &s, int l, int r )
    {
        while( l < r ) {
            if( s[ l++ ] != s[ r-- ] )
                return false;
        }
        
        return true;
    }
    
    string longestPalindrome(string s) {
        std::string res;
        for( int i = 0; i < s.size(); ++i ) {
            for( int j = s.size() - 1; j >= i; --j ) {
                if( ( j - i + 1 ) <= res.size() )
                    break;
                
                if( is_anagram( s, i, j ) && j - i + 1 > res.size() )
                    res = s.substr( i, j - i + 1 );
            }
        }
        
        return res;
    }
};

// time: O( N^2 )
// space: O( 1 )
class Solution {
public:
    string longestPalindrome( const string &s )
    {
        int start{ 0 };
        int end{ 0 };
        for( int i = 0; i < s.size(); ++i ) {
            auto len1 = expandPalindrome( s, i, i );
            auto len2 = expandPalindrome( s, i, i + 1 );
            int len = std::max( len2, len1 );
            if( len > end - start ) {
                end = i + len / 2;
                start = i - ( len - 1 ) / 2;
            }
        }
        
        return std::move( s.substr( start, end + 1 - start ) );
    }
    
    int expandPalindrome( const std::string &str, int left, int right )
    {
        while( left >= 0 && right < str.size() && 
               str[ left ] == str[ right ] ) {
            --left;
            ++right;
        }
        
        return right - left - 1;
    }
};

class Solution {
public:
    
    // time O( N^2 ), where N == s.size()
    // space O( N^2 ), where N == s.size()
    string longestPalindrome(string s)
    {
        if( ( s.size() <= 1 ) || ( s.size() == 2 && s[ 0 ] == s[ 1 ] ) )
            return s;
        
        int l{ 0 };
        int r{ 0 };
        std::vector<std::vector<bool>> dp( s.size(), std::vector<bool>( s.size() ) );
        for( int i = s.size() - 1; i >= 0; --i ) {
            for( int j = i; j < s.size(); ++j ) {
                dp[ i ][ j ] = ( s[ i ] == s[ j ] && ( j - i < 3 || dp[ i + 1 ][ j - 1 ] ) );
                
                if( dp[ i ][ j ] && ( ( !l && !r ) || ( r - l < j - i ) ) ) {
                    r = j;
                    l = i;
                }
            }
        }
        
        return s.substr( l, r - l + 1 );
    }
};

class Solution {
public:
    // space O( 1 )
    // time O( N ), where N == s.size()
    string longestPalindrome(string s)
    {
        if( s.size() <= 1 || ( s.size() == 2 && ( s[ 0 ] == s[ 1 ] ) ) )
            return s;
        
        int l{ 0 };
        int r{ 0 };
        for( int i = 0; i < s.size(); ) {
            int j = i;
            int k = i;
            
            while( k < s.size() - 1 && s[ k ] == s[ k + 1 ] )
                ++k;
            
            i = k + 1;
            while( k < s.size() && j > 0 && s[ j - 1 ] == s[ k + 1 ] ) {
                ++k;
                --j;
            }
            
            if( r - l < k - j ) {
                r = k;
                l = j;
            }
        }
        
        return s.substr( l, r - l + 1 );
    }
};
