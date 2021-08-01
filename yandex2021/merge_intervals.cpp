class Solution {
public:
    // space O( log N )
    // time O( N log N ), N == sizeof( intervals )
    vector<vector<int>> merge( vector<vector<int>>& intervals )
    {
        // time O( N log N ), N == sizeof( intervals )
        std::sort( std::begin( intervals ), std::end( intervals ), 
                  []( const auto &inter1, const auto &inter2 ){
                      return ( inter1[ 0 ] < inter2[ 0 ] ||
                              ( inter1[ 0 ] == inter2[ 0 ] &&
                              inter1[ 1 ] < inter2[ 1 ] ) );
                  } );
        
        std::vector<std::vector<int>> res;
        // time O( N ), N == sizeof( intervals )
        for( int i = 0; i < intervals.size(); ) {
            auto inter = intervals[ i ];
            while( i < intervals.size() && are_overlap( inter, intervals[ i ] ) ) {
                inter[ 0 ] = std::min( inter[ 0 ], intervals[ i ][ 0 ] );
                inter[ 1 ] = std::max( inter[ 1 ], intervals[ i ][ 1 ] );
                ++i;
            }
            
            res.push_back( inter );
        }
        
        return res;
    }
    
    bool are_overlap( const std::vector<int> &inter1, const std::vector<int> &inter2 )
    {
        return inter1[ 1 ] >= inter2[ 0 ] || inter2[ 1 ] <= inter1[ 1 ];
    }
};
