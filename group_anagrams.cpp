// space O( N ), where N is the size of the strs
// time O( N x M ), where N - size of strs and M - size of the longest element in strs
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
