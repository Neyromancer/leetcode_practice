class Solution {
public:
    vector<int> findAnagrams( string s, string p )
    {
        if( s.size() < p.size() )
            return {};
        
        std::array<int, 26> st{};
        for( char ch : p )
            --st[ ch - 'a' ];
        
        std::vector<int> res;
        for( int i = 0; i <= s.size() - p.size(); ++i ) {
            if( st[ s[ i ] - 'a' ] != 0 ) {
                auto tmp = st;
                int j = 0;
                while( j < p.size() && ++tmp[ s[ i + j ] - 'a' ] <= 0 )
                    ++j;
                
                if( j == p.size() )
                    res.push_back( i );
            }
        }
        
        return res;
    }
};
