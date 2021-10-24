class Solution {
public:
    // time O( sizeof( s ) )
    // space O( 1 )
    int count_uniqs( const std::string &s ) {
        std::array<int, 27> st{};
        int uniqs{ 0 };
        for( auto ch : s ) {
            if( !st[ ch - 'a' ] ) // O( 1 )
                ++uniqs;

            ++st[ ch - 'a' ]; // O( 1 )
        }

        return uniqs;
    }

    // time O( uniqs( s ) * sizeof( s ) )
    // space O( 1 )
    int longestSubstring(string s, int k)
    {
        if( ( s.size() * k == 0 ) || k > s.size() )
            return 0;
        
        int uniqs = count_uniqs( s );
        int len{ 0 };
        for( int uniqs_limit = 1; uniqs_limit <= uniqs; ++uniqs_limit ) {
            int cnt_kmet{ 0 };
            int cur_uniqs{ 0 };
            std::array<int, 27> st{};
            
            int l{ 0 };
            int r{ 0 };
            while( r < s.size() ) {
                if( st[ s[ r ] - 'a' ] == 0 ) // O( 1 )
                    ++cur_uniqs;
                
                if( ++st[ s[ r ] - 'a' ] == k )
                    ++cnt_kmet;
                
                while( l < r && cur_uniqs > uniqs_limit ) {
                    if( st[ s[ l ] - 'a' ]-- == k ) // O( 1 )
                        --cnt_kmet;
                    
                    if( st[ s[ l ] - 'a' ] == 0 ) // O( 1 )
                        --cur_uniqs;
                    
                    ++l;
                }
                
                if( cur_uniqs && cnt_kmet == cur_uniqs )
                    len = std::max( len, r - l + 1 );  // O( 1 )
                
                ++r;
            }
        }
        
        return len;
    }
};
