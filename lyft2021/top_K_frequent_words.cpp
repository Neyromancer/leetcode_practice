class Solution {
public:
    /**
    1. посчитать сколько раз встречается каждое из слов
    2. отсортировать по частоте появления и по алфавиту
    3. достать k наиболее часто встречающихся
    */
    // space O( N ), where N is the number of words
    // time O( N log N ), where N is the number of words
    vector<string> topKFrequent( vector<string>& words, int k )
    {
        std::unordered_map<std::string, int> frequency;
        for( const auto &word : words )
            ++frequency[ word ]; // O( 1 )
        
        std::vector<std::pair<int, std::string>> word_freq;
        for( auto &[ w, freq ] : frequency )
            word_freq.emplace_back( freq, w ); // O( 1 )
        
        // O( N log N ), where N == word_freq.size
        std::sort( std::begin( word_freq ), std::end( word_freq ), 
                  []( const auto &el1, const auto &el2 ){
                      return ( el1.first > el2.first || 
                              ( el1.first == el2.first && 
                                el1.second < el2.second ) );
                  } );

        std::vector<std::string> res( k );
        for( int i = 0; i < k; ++i )
            res[ i ] = word_freq[ i ].second;
        
        return res;
    }
};
