// space O( N ), where N is the size of the strs
// time O( N x M x log M ), where N - size of strs and M - size of the longest element in strs
std::vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::vector<std::vector<std::string>> res;
    std::unordered_map<std::string, int> storage;
    for( int i = 0; i < strs.size(); ++i ) {
        auto tmp = strs[ i ];
        std::sort( std::begin( tmp ), std::end( tmp ) );
        if( storage.count( tmp ) == 0 ) {
            storage[ tmp ] = res.size();
            res.push_back( {} );
        }
            
        res[ storage[ tmp ] ].push_back( strs[ i ] );
    }
        
    return res;
}

// space O( N )
// time O( N x M + N ), where N number of string, M - the longest string
void count_sort( std::string &str ) {
    std::array<int, 26> alpha{};
    for( auto ch : str )
        ++alpha[ ch - 'a' ];
        
    int i = 0;
    for( int j = 0; j < alpha.size(); ++j ) {
        while( alpha[ j ]-- > 0 )
            str[ i++ ] = 'a' + j;
    }
}
    
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::vector<std::vector<std::string>> res;
    std::unordered_map<std::string, int> storage;
    for( int i = 0; i < strs.size(); ++i ) {
        auto tmp = strs[ i ];
        count_sort( tmp );
        if( storage.count( tmp ) == 0 ) {
            storage[ tmp ] = res.size();
            res.push_back( {} );
        }

        res[ storage[ tmp ] ].push_back( strs[ i ] );
    }

    return res;
}
