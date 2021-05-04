class Solution {
public:
    // space O( N ), where N is the size of stones
    // time O( N log N ), where N is the size of stones
    int lastStoneWeight(vector<int>& stones)
    {
        if( stones.empty() )
            return 0;
        
        std::priority_queue<int> q;
        for( auto n : stones )
            q.push( n );
        
        while( q.size() > 1 ) {
            auto n1 = q.top();
            q.pop();
            auto n2 = q.top();
            q.pop();
            auto val = std::min( n1, n2 );
            if( n1 -= val )
                q.push( n1 );
            
            if( n2 -= val )
                q.push( n2 );
        }
        
        return q.empty() ? 0 : q.top();
    }
};
