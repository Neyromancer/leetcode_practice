// time O( ( N - L )L ), where N == s.size() and L == 10
// space O( ( N - L )L ), where N == s.size() and L == 10
vector<string> findRepeatedDnaSequences(string s)
{
    if( s.size() < 10 )
        return {};

    std::unordered_map<std::string, int> st;
    std::vector<std::string> res;
    for( int l = 0; l <= s.size() - 10; ++l ) {
        if( auto key = s.substr( l, 10 ); st[ key ]++ == 1 ) {
            res.push_back( key );
            continue;
        }
    }
        
    return res;
}

    std::uint64_t calc_hash( const std::vector<int> &nums, int L, int a )
    {
        std::uint64_t h{ 0 };
        for( int i = 0; i < L; ++i )
            h = h * a + nums[ i ];
        return h;
    }
    
    vector<string> findRepeatedDnaSequences(string s)
    {
        int L{ 10 };
        int a{ 4 };
        if( s.size() < L )
            return {};
        int aL = static_cast<int>( std::pow( a, L ) );
        std::unordered_map<char,int> st{
            {'A', 0 }, { 'C', 1 }, { 'G', 2 }, { 'T', 3 }
        };
        
        std::vector<int> nums( s.size() );
        for( int i = 0; i < nums.size(); ++i )
            nums[ i ] = st[ s[ i ] ];
        
        std::uint64_t h = calc_hash( nums, L, a );
        std::set<std::uint64_t> seen;
        seen.insert( h );
        std::set<std::string> output;
        for( int i = 1; i <= nums.size() - L; ++i ) {
            h = h * a - nums[ i - 1 ] * aL + nums[ i + L - 1 ];
            if( seen.count( h ) )
                output.insert( s.substr( i, L ) );
            
            seen.insert( h );
        }
        
        std::vector<std::string> res;
        res.reserve( output.size() );
        for( const auto &el : output )
            res.push_back( el );
        
        return res;
    }
