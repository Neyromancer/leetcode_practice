class Solution {
public:
    // time O( N ), N == sizeof( s )
    // space O( 1 )
    bool isPalindrome( string s )
    {
        int l{ 0 };
        int r = s.size() - 1;
        while( l <= r ) {
            while( l < r && !std::isalnum( s[ l ] ) )
                ++l;
            while( l < r && !std::isalnum( s[ r ] ) )
                --r;
            
            if( std::tolower( s[ l++ ] ) != std::tolower( s[ r-- ] ) )
                return false;
        }
        
        return true;
    }
};
