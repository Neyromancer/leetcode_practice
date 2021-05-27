class Solution {
public:
    // Top-down solution
    // space O( N^2 ), where N == s.size()
    // time O( N^2 ), where N == s.size()
    int countSubstrings(string s)
    {
        if( s.size() == 1 )
            return 1;
        
        int cnt{ 0 };
        std::vector<std::vector<bool>> dp( s.size(), std::vector<bool>( s.size() ) );
        for( int l = s.size() - 1; l >= 0; --l ) {
            for( int r = l; r < s.size(); ++r ) {
                if( s[ r ] == s[ l ] && ( ( r - l <= 2 ) || dp[ l + 1 ][ r - 1 ] ) ) {
                    dp[ l ][ r ] = true;
                    ++cnt;
                }
            }
        }
        
        return cnt;        
    }
};

class Solution {
public:
    // time O( N ), where N == s.size()
    // space O( 1 )
    int countSubstrings(string s) 
    {
        if( s.size() == 1 )
            return 1;
        
        int cnt = s.size();
        int i = 0;
        while( i < s.size() ) {
            int l = i;
            int r = i;
            while( r < s.size() - 1 && s[ r ] == s[ r + 1 ] ) {
                ++r;
                ++cnt;
            }

            while( l - 1 >= 0 && r + 1 < s.size() && s[ l - 1 ] == s[ r + 1 ] ) {
                ++r;
                --l;
                ++cnt;
            }
            
            ++i;
        }
        
        return cnt;
    }
};

class Solution {
public:
    // time O( N^2 ), where N == s.size()
    // space O( 1 )
    int countSubstrings(string s)
    {
        if( s.size()  == 1 )
            return 1;
        
        int cnt{ 0 };
        for( int i = 0; i < s.size(); ++i ) {
            cnt += calc_palindromes( s, i, i );
            cnt += calc_palindromes( s, i, i + 1 );
        }
        
        return cnt;
    }
    
    int calc_palindromes( std::string_view s, int l, int r )
    {
        int cnt{ 0 };
        while( l >= 0 && r < s.size() && s[ l-- ] == s[ r++ ] )
            ++cnt;
        
        return cnt;
    }
};
