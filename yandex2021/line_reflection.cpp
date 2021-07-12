class Solution {
    /**
[[1,1],[-1,1]]
[[1,1],[-1,-1]]
[[2,1],[4,1],[5,1]]
[[2,3],[3,3],[4,3]]
[[2,1],[4,1],[5,1],[2,3],[3,3],[4,3]]
[[4,2]]
[[2,5],[4,5]]
[[2,3],[3,3],[4,3],[2,5],[4,5]]
[[2,3],[3,3],[4,3],[2,5],[4,5],[3,6]]
[[2,3],[3,3],[4,3],[2,5],[4,5],[3,6],[4,2]]
[[-16,1],[16,1],[16,1]]
    */
    
public:
    // time ( N * M ), N == number of layers and M points on the layer
    // space O( N ), number of points
    bool isReflected(vector<vector<int>>& points)
    {
        std::unordered_map<int, std::set<int>> ptrs_on_layers;
        // O( N log N ), N == sizeof( points )
        for( const auto &ptr : points )
            ptrs_on_layers[ ptr[ 1 ] ].insert( ptr[ 0 ] ); // O( log N ), where N == size of ptrs_on_layers
        
        double x_axis = std::numeric_limits<double>::max();
        // O( N * M ), N == sizeof( ptrs_on_layers ), M == sizeof( ptrs )
        for( auto &[ layer, ptrs ] : ptrs_on_layers ) {
            auto axis = get_axis( ptrs );
            if( axis.has_value() ) {
                if( x_axis == std::numeric_limits<double>::max() ) {
                    x_axis = axis.value();
                } else if( x_axis != axis.value() )
                    return false;
            } else
                return false;
        }
        
        return true;
    }
    
    std::optional<double> get_axis( std::set<int> &vc )
    {
        std::vector<int> st;
        st.reserve( vc.size() );
        // O( N ), N == sizeof( vc )
        for( auto &p : vc )
            st.push_back( p );
            
        double axis = std::numeric_limits<double>::max();
        int l{ 0 };
        int r = st.size() - 1;
        // std::cout << "size " << st.size() << std::endl;
        // O( N ), sizeof( vc )
        while( l <= r ) {
            auto sym = st[ l ] + ( st[ r ] - st[ l ] ) / 2.0;
            if( axis == std::numeric_limits<double>::max() )
                axis = sym;
            else if( axis != sym )
                return std::nullopt;
            
            ++l;
            --r;
        }
        
        return axis;
    }
};
