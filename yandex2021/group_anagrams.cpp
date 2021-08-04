class Solution {
public:
    // time O( N x M ), N == strs.size, M == sizeof( max( strs ) )
    // space O( N ), N == strs.size
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        std::map<std::vector<int>, std::vector<std::string>> st;
        for( const auto &str : strs ) {
            auto key = make_key( str );
            st[ key ].push_back( str );
        }
        
        std::vector<std::vector<std::string>> res;
        for( const auto &[ key, vals ] : st )
            res.push_back( vals );
        
        return res;
    }
    
    // time O( N ), N == str.size()
    // space O( 1 )
    std::vector<int> make_key( std::string_view str )
    {
        if( str.empty() )
            return {};

        std::vector<int> arr( 27 );
        for( char ch : str )
            ++arr[ ch - 'a' ];
        
        return arr;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams( vector<string>& strs )
    {
        std::unordered_map<std::string, std::vector<std::string>> st;
        for( const auto &str : strs ) {
            auto key = calc_key( str );
            st[ key ].push_back( str );
        }
        
        std::vector<std::vector<std::string>> res;
        for( auto &&[ key, vals ] : st )
            res.push_back( vals );
        
        return res;
    }
    
    std::string calc_key( std::string_view seq )
    {
        std::string arr( 26, '0' );
        for( auto ch : seq )
            arr[ ch - 'a' ] = ( ( arr[ ch - 'a' ] - '0' ) + 1 ) + '0';
        
        return arr;
    }
};
