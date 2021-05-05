class Solution {
public:
    // time O( N log N ), where N == nums.size
    // space O( N ), where N == nums.size
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        std::unordered_map<int, int> st;
        for( auto n : nums )
            ++st[ n ]; // O( 1 )
        
        auto cmp = []( const std::pair<int, int> &n1,
                       const std::pair<int,int> &n2 ){
            return n1.second <= n2.second;
        };
        std::priority_queue<std::pair<int,int>,
                            std::vector<std::pair<int,int>>,
                            decltype( cmp )> q( cmp );
        for( auto el : st )
            q.push( std::make_pair( el.first, el.second ) ); // O( log N ) N == nums.size()
        
        std::vector<int> res;
        while( k-- > 0 ) {
            res.push_back( q.top().first ); // O( 1 )
            q.pop();
        }
        
        return res;
    }
};


