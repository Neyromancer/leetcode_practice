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
