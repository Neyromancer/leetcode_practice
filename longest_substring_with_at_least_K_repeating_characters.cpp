class Solution {
public:
    /*
        s = ababbc k = 2
        
        
       r    |
        a b a b b c
        0 1 2 3 4 5
       l|

        
        sz = 6
        unique_num = 3
        len = 0
        num_unique_reach_k = 0
        uniques = 0
        l = 0
        r = 0
        
        alph 0 1 0 0 0 0 0 0 0 0  0  0  0  0  0  0
             0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
    */
    
    std::size_t count_unique( const std::string &s )
    {
        std::unordered_set<int> st;
        for( char ch : s )
            st.insert( ch - 'a' );
        return st.size();
    }

    int longestSubstring(string s, int k)
    {
        std::array<int, 27> alph;
        int sz = static_cast<int>( s.size() );
        auto unique_num = count_unique( s );
        int len{ 0 };
        for( std::size_t u = 1; u <= unique_num; ++u ) {  // 1
            int num_unique_reach_k{ 0 };
            int l{ 0 }; // 0
            int r{ 0 }; // 2
            int uniques{ 0 }; // 1
            alph.fill(0);
            while( r < sz ) {
                if( uniques <= u ) {
                    int idx = s[ r++ ] - 'a'; // 2
                    if( alph[ idx ] == 0 )
                        ++uniques;
                    alph[ idx ]++;
                    if( alph[ idx ] == k )
                        ++num_unique_reach_k;
                } else {
                    int idx = s[ l ] - 'a'; // 0
                    if( alph[ idx ] == k )
                        --num_unique_reach_k;

                    alph[ idx ]--;
                    if( alph[ idx ] == 0 )
                        --uniques;

                    ++l;
                }
                
                if( uniques == u && uniques == num_unique_reach_k )
                    len = std::max( len, r - l );
            }
        }
        
        return len;
    }
};
