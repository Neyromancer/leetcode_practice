class Solution {
public:
    // time O( sizeof( nums ) x log( sizeof( nums ) ) )
    // time O( log( sizeof( nums ) ) )
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        /**
        1. init max heap (max) with nums. max heap will have the size of k
        2. fill max heap with elements from nums in the arrange k
        3. init result array
        4. place current max from max_heap to this returning array
        5. start for-loop from position k
        6. every move to the right add index and value to unordered_map and max_heap
        7. remove from unordered_map and max_heap element from nums under the index (right - k), i.e. first element in the window range
        8. get current maximum from max_heap
        9. move window till right reach end of nums
        10. repeat 8 - 11
        11. return result
        */
        
        std::map<int, int, std::greater<int>> max_heap;
        for( int i = 0; i < k; ++i )
            ++max_heap[ nums[ i ] ]; // O( log( sizeof( k ) ) )
        
        std::vector<int> res;
        res.push_back( std::get<0>( *std::begin( max_heap ) ) );
        for( int r = k; r < nums.size(); ++r ) {
            ++max_heap[ nums[ r ] ]; // O( log( sizeof( k ) ) )
            --max_heap[ nums[ r - k ] ]; // O( log( sizeof( k ) ) )
            if( !max_heap[ nums[ r - k ] ] )
                max_heap.erase( nums[ r - k ] );

            res.push_back( std::get<0>(*std::begin(max_heap)) );
        }
        
        return res;
    }
};

class Solution {
    std::deque<int> q;
public:
    /**
    [1,3,-1,-3,5,3,6,7]
3
[1,-1]
1
[1]
1
[1,-1]
1
[9,11]
2
[4,-2]
2
    
    */
    void clean( const std::vector<int>& vc, int i, int k )
    {
        if( !q.empty() && q.front() == i - k )
            q.pop_front();
        
        while( !q.empty() && vc[ i ] > vc[ q.back() ] )
            q.pop_back();
    }
    
    // space O( sizeof( nums ) )
    // time O( sizeof( nums ) )
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        if( nums.size() * k == 0 )
            return {};
        
        if( k == 1 )
            return nums;
        
        for( int i = 0; i < k; ++i ) {
            clean( nums, i, k );
            q.push_back( i ); // O( 1 )
        }
        
        std::vector<int> res;
        res.reserve( nums.size() - k + 1 );
        res.push_back( nums[ q.front() ] ); // O( 1 )
        
        for( int i = k; i < nums.size(); ++i ) {
            clean( nums, i, k );
            q.push_back( i ); // O( 1 )
            res.push_back( nums[ q.front() ] ); // O( 1 )
        }
        
        return res;
    }
};
