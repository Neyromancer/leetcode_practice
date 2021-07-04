class Solution {
public:
    // time O( sizeof( s ) )
    // space O( 1 )
    int longestPalindrome( string s )
    {
        std::array<int, 100> alph{}; // O( 100 )
        // O( sizeof( s ) )
        for( auto ch : s )
            ++alph[ ch - 'A' ]; // O( 1 )
        
        int odd_max{ 0 };
        int res{ 0 };
        for( auto n : alph ) {
            if( n > 0 && !( n % 2 ) )
                res += n;
            else if( n > 0 && ( n % 2 ) )
            {
                res += n - 1;
                odd_max = 1;
            }
        }
        
        return res + odd_max;
    }
};

class Solution {
public:
    // time O( N ) where N is the size of s
    // space O( 1 )
    int longestPalindrome(string s)
    {
        if( s.empty() )
            return 0;
        
        std::unordered_set<int> st;
        int cnt{ 0 };
        for( auto ch : s ) {
            if( st.count( ch ) ) {
                ++cnt;
                st.erase( ch );
            } else {
                st.insert( ch );
            }
        }
        
        if( !st.empty() )
            return cnt * 2 + 1;
        
        return cnt * 2;
    }
};

class Solution {
public:
    // time O( N ), where N is the size of s
    // space O( 1 )
    int longestPalindrome(string s)
    {
        if( s.empty() )
            return 0;
        
        std::array<int, 27> lower{};
        std::array<int, 27> upper{};
        for( auto ch : s ) {
            if( ch >= static_cast<int>( 'a' ) )
                ++lower[ ch - 'a' ];
            else
                ++upper[ ch - 'A' ];
        }
        
        int res{ 0 };
        for( std::size_t i = 0; i < lower.size(); ++i ) {
            res += lower[ i ] / 2;
            res += upper[ i ] / 2;
        }
        
        return res * 2 == s.size() ? s.size() : res * 2 + 1;
    }
};

class Solution {
public:
    // time O( N ), where N == s.size()
    // space O( 1 )
    int longestPalindrome(string s)
    {
        if( s.empty() )
            return 0;
        
        std::array<int, 128> chars{};
        for( auto ch : s )
            ++chars[ ch ];
        
        int cnt_odd{ 0 };
        for( std::size_t i = 0; i < chars.size(); ++i )
            if( chars[ i ] % 2 )
                ++cnt_odd;
        
        return cnt_odd > 1 ? s.size() - cnt_odd + 1 : s.size();
    }
};
