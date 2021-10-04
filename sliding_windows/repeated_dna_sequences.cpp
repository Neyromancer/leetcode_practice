class Solution {
public:
    // time O( ( N - 10 ) * 10 )
    // space O( ( N - 10 ) * 10 )
    vector<string> findRepeatedDnaSequences(string s)
    {
        if( s.size() < 10 )
            return {};

        std::unordered_map<std::string, int> st;
        std::vector<std::string> res;
        for( int i = 0; i <= s.size() - 10; ++i ) {
            auto tmp = s.substr( i, 10 ); // O( 10 )
            if( st[ tmp ] == 1 )
                res.push_back( tmp ); // O( 1 )
            ++st[ tmp ]; // O( 1 )
        }
        
        return res;
    }
};

class Solution {
    std::unordered_map<char,int> dict {
            { 'A', 0 },
            { 'C', 1 },
            { 'G', 2 },
            { 'T', 3 }
        };
public:
    int calc_hash( std::string_view s, int start ) {
        int hash{ 0 };
        for( int i = 0; i < 10 && ( start + i < s.size() ); ++i ) {
            hash += dict[ s[ i + start ] ] * static_cast<int>( std::pow( 4, 10 - i - 1 ) );
        }
            
        return hash;
    }
    
    vector<string> findRepeatedDnaSequences(string s)
    {
        if( s.size() < 10 )
            return {};

        std::unordered_map<int, int> st;
        std::vector<std::string> res;
        for( int i = 0; i <= s.size() - 10; ++i ) {
            int hash = calc_hash( s, i );
            if( st[ hash ] == 1 )
                res.push_back( s.substr( i, 10 ) );
            ++st[ hash ];
        }
        
        return res;
    }
};

class Solution {
public:
    // time O( sizeof( s )
    // space O( sizeof( s ) )
    vector<string> findRepeatedDnaSequences(string s)
    {
        if( s.size() < 10 )
            return {};
        
        std::unordered_map<int, int> seen;
        std::vector<std::string> res;
        int bitmask{ 0 };
        for( int i = 0; i <= s.size() - 10; ++i ) {
            bitmask = count_hash( bitmask, i, s );
            if( seen[ bitmask ] == 1 ) // O( 1 )
                res.push_back( s.substr( i, 10 ) ); // O( 10 )
            
            ++seen[ bitmask ];
        }
        
        return res;
    }
    
    // time O( 10 )
    // space O( 1 )
    int count_hash( int bitmask, int start, const std::string &s )
    {
        const static std::unordered_map<char, int> dict{
            {'A', 0 }, { 'C', 1 }, { 'G', 2 }, { 'T', 3 }  
        };
        
        if( start ) {
            bitmask <<= 2;
            bitmask |= dict.at( s[ start + 10 - 1 ] ); // O( 1 )
            bitmask &= ~( 3 << 2 * 10 );
            return bitmask;
        }
        
        for( int i = 0; i < 10; ++i ) {
            bitmask <<= 2;
            bitmask |= dict.at( s[ i ] ); // O( 1 )
        }
        
        return bitmask;
    }
};
