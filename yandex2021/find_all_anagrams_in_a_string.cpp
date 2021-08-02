class Solution {
public:
    // time O( sizeof( s ) )
    // space O( 1 )
    vector<int> findAnagrams(string s, string p)
    {
        if( p.size() > s.size() )
            return {};
        
        std::array<int, 27> alph_p{};
        for( char ch : p )
            ++alph_p[ ch - 'a' ];
        
        std::array<int, 27> alph_s{};
        for( int i = 0; i < p.size(); ++i )
            ++alph_s[ s[ i ] - 'a' ];
        
        std::vector<int> res;
        if( alph_p == alph_s )
            res.push_back( 0 );
        
        for( int i = p.size(); i < s.size(); ++i ) {
            --alph_s[ s[ i - p.size() ] - 'a' ];
            ++alph_s[ s[ i ] - 'a' ];
            
            if( alph_s == alph_p )
                res.push_back( i - p.size() + 1 );
        }
        
        return res;
    }
};
