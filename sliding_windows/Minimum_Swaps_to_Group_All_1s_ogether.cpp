class Solution {
    /*
    [0,1,1]
    [1,0,1,0,1]
[0,0,0,1,0]
[1,0,1,0,1,0,0,1,1,0,1]
[1,0,1,0,1,0,1,1,1,0,1,0,0,1,1,1,0,0,1,1,1,0,1,0,1,1,0,0,0,1,1,1,1,0,0,1]
[0,0,0,0,0]
[1,1,1,1,1]
[0,1]
[1,0,1]
[0,1,1]
[1,0,0]
[1]
[0]
    */
public:
    // space O( 1 )
    // time O( sizeof( data ) )
    int minSwaps(vector<int>& data)
    {
        int ones = std::count( std::begin( data ), std::end( data ), 1 );
        int zeroes{ 0 };
        for( int i = 0; i < ones; ++i )
            if( !data[ i ] )
                ++zeroes;
        
        int swaps = zeroes;
        for( int i = ones; i < data.size(); ++i ) {
            if( !data[ i ] )
                ++zeroes;
            
            if( !data[ i - ones ] )
                --zeroes;

            swaps = std::min( swaps, zeroes );
        }
        
        return swaps;
    }
};

class Solution {
public:
    // time O( sizeof( data ) )
    // space O( sizeof( data ) )
    int minSwaps(vector<int>& data)
    {
         // O( sizeof( data ) )
        int ones = std::count( std::begin( data ), std::end( data ), 1 );
        int local_ones{ 0 };
        int nswaps{ std::numeric_limits<int>::max() };
        std::deque<int> q;
        for( int r = 0; r < data.size(); ++r ) {
            q.push_back( data[ r ] ); // O( 1 )
            local_ones += q.back(); // O( 1 )
            if( q.size() > ones ) {
                local_ones -= q.front(); // O( 1 )
                q.pop_front(); // O( 1 )
            }
            
            nswaps = std::min( nswaps, ones - local_ones );
        }
        
        return nswaps;
    }
};
