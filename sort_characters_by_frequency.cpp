// space O( N ), where N is the size of s
// time O( K log N ), where K is the number of the most frequent character, N is number of unique characters
class Solution {
public:
    string frequencySort(string s) 
    {
        std::unordered_map<char, int> st;
        for( auto ch : s )
            ++st[ ch ]; // O( 1 )
        
        auto cmp = []( const std::pair<char, int> &el1, const std::pair<char, int> &el2 ){
            return el1.second < el2.second;
        };
        std::priority_queue<std::pair<char, int>,
                            std::vector<std::pair<char,int>>, 
                            decltype(cmp) > q( cmp );
        // O( N log( N ) )
        for( const auto &el : st )
            q.push( el ); // O( log( N ) )
        
        std::string res;
        while( !q.empty() ) {
            auto node = q.top(); // O( 1 )
            q.pop(); // O( log N )
            // O( N ), where N is the number of characters to append
            res.append( node.second, node.first ); 
        }
        
        return res;
    }
};
