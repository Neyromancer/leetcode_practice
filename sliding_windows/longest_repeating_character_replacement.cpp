class Solution {
public:
    // O( <= 26 )
    std::unordered_set<char> collect_uniques( const std::string &s ) {
        std::unordered_set<char> st;
        for( char ch : s )
            st.insert(ch); // O( 1 )
        return st;
    }
    
    // time O( uniqs( s ) * sizeof( s ) )
    // space O( uniqs( s ) <= 26 )
    int characterReplacement(string s, int k)
    {
        if( s.empty() )
            return 0;
        
        std::unordered_set<char> uniqs = collect_uniques(s);
        int len{ 0 };
        for( auto ch : uniqs ) {
            int l{ 0 };
            int r{ 0 };
            int cnt{ k };
            while( r < s.size() ) {
                if( ch != s[ r ] )
                    --cnt;

                while( l < r && cnt < 0 ) {
                    if( ch != s[ l ] )
                        ++cnt;
                    ++l;
                }
                
                len = std::max( len, r - l + 1 );
                ++r;
            }
        }
        
        return len;
    }
};

class Solution {
public:
    // time O( sizeof( s ) )
    // space O( 1 )
    int characterReplacement(string s, int k) {
        std::array<int,27> alph{};
        int diff{ 0 };
        int len{ 0 };
        int l{ 0 };
        for( int r = 0; r < s.size(); ++r ) {
            diff = std::max( diff, ++alph[ s[ r ] - 'A' ] );
            while( r - l + 1 - diff > k )
                --alph[ s[ l++ ] - 'A' ];
            
            len = std::max( len, r - l + 1 );
        }
        
        return len;
    }
};
