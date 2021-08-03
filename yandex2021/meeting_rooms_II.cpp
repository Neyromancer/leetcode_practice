class Solution {
public:
    /*
[[0,30],[5,10],[15,20]]
[[7,10],[2,4]]
[[13,15],[1,13]]
[[9,10],[4,9],[4,17]]
[[2,11],[6,16],[11,16]]
[[2,7]]
    
    */
    // time O( sizeof( intervals ) * log( sizeof( intervals ) ) )
    // space O( sizeof( intervals ) )
    int minMeetingRooms( vector<vector<int>>& intervals )
    {
        // time O( sizeof( intervals ) * log( sizeof( intervals ) ) )
        std::sort( std::begin( intervals ), std::end( intervals ), 
                  []( const auto &inter1, const auto &inter2 ){
                      return ( ( inter1[ 0 ] < inter2[ 0 ] ) || 
                              ( inter1[ 0 ] == inter2[ 0 ] && 
                               inter1[ 1 ] < inter2[ 1 ] ) );
                  } );
        std::priority_queue<int, std::vector<int>, std::greater<int>> q;
        // time O( sizeof( intervals ) )
        for( int i = 0; i < intervals.size(); ++i ) {
            if( !q.empty() && q.top() <= intervals[ i ][ 0 ] )
                q.pop(); // log( sizeof( queue ) )
            
            q.push( intervals[ i ][ 1 ] ); // log( sizeof( queue ) )
        }
        
        return q.size();
    }
};
