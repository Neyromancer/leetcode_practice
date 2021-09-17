class Solution {
public:
    // time O( sizeof( s ) )
    // space O( 1 )
    std::unordered_set<char>
    find_all_uniques( std::string_view s )
    {
        std::unordered_set<char> st;
        for( char ch : s )
            st.insert( ch );
        return st;
    }
    
    // time O( sizeof( s ) )
    // space O( 1 )
    int characterReplacement(string s, int k) 
    {
        auto uniques = find_all_uniques(s);
        int len{ 0 };

        for( char ch : uniques ) {  // time O( 1 )
            int l{ 0 };
            int r{ 0 };
            int cnt = k;
            while( r < s.size() ) { // O( sizeof( s ))
                if( ch != s[ r ] )
                    --cnt;
                
                while( cnt < 0 && l < r ) {
                    if( ch != s[ l++ ] )
                        ++cnt;
                }
                
                len = std::max( len, r - l + 1 );
                ++r;
            }
            
            len = std::max( len, r - l );
        }
        
        return len;
    }
};
