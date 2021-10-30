class Solution {
public:
    /*
    "barfoothefoobarman"
["foo","bar"]
"wordgoodgoodgoodbestword"
["word","good","best","word"]
"barfoofoobarthefoobarman"
["bar","foo","the"]
"wordgoodgoodgoodbestword"
["word","good","best","good"]
    
    */
    // time O( N * M ), where N == s.size() and M == words.front().size()
    // space O( sizeof( words ) )
    vector<int> findSubstring(string s, vector<string>& words)
    {
        std::unordered_map<std::string, int> st;
        for( const auto& word : words )
            ++st[ word ]; // O( 1 )
        
        int sz = static_cast<int>( s.size() );
        int wlen = words.front().size(); // O( 1 )
        int wnum = words.size(); // O( 1 )
        std::vector<int> res;
        for( int i = 0; i <= sz - wlen * wnum; ++i ) {
            std::unordered_map<std::string, int> seen;
            int j = 0;
            for( j; j < wnum; ++j ) {
                auto word = s.substr( i + j * wlen, wlen ); // O( wlen )
                if( st.count( word ) ) { // O( 1 )
                    if( ++seen[ word ] > st[ word ] ) // O( 1 )
                        break;
                    
                } else
                    break;
            }
            
            if( j == wnum )
                res.push_back( i ); // O( 1 )
        }
        
        return res;
    }
};
