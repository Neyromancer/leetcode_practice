class Solution {
public:
    // time O( sizeof( s ) )
    // space O( 1 )
    vector<int> findAnagrams(string s, string p)
    {
        if( p.size() > s.size() )
            return {};
        
        std::array<int, 27> s_arr{};
        std::array<int, 27> p_arr{};
        for( int i = 0; i < p.size(); ++i ) {
            ++s_arr[ s[ i ] - 'a' ];
            ++p_arr[ p[ i ] - 'a' ];
        }
        
        std::vector<int> res;
        if( s_arr == p_arr )
            res.push_back( 0 );

        for( std::size_t i = p.size(); i < s.size(); ++i ) { // i = 7
            --s_arr[ s[ i - p.size() ] - 'a' ];
            ++s_arr[ s[ i ] - 'a' ];

            if( s_arr == p_arr )
                res.push_back( i - p.size() + 1 );
        }
        
        return res;
    }
};
