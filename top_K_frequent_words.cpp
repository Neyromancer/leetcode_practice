class Solution {
public:
    // time O( k log N )
    // space O( N )
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        std::unordered_map<std::string, int> st;
        for( auto w : words )
            ++st[ w ]; // O( 1 )
        
        auto cmp = []( std::pair<std::string, int> &el1,
                       std::pair<std::string, int> &el2 ){
            return ( ( el1.second < el2.second ) ||
                     ( el1.second == el2.second && 
                       el1.first > el2.first ) );
        };
        
        std::priority_queue<std::pair<std::string, int>,
                            std::vector<std::pair<std::string, int>>,
                            decltype( cmp )> q( cmp );

        for( auto &&el : st )
            q.push( std::move( el ) ); // O( 1 )

        std::vector<std::string> res;
        while( k-- > 0 ) {
            auto node = q.top(); // O( 1 )
            q.pop(); // O( log N )
            res.push_back( node.first ); // O( log N  )
        }
        
        return res;
    }
};

