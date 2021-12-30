class Solution {
public:
    // time O( sizeof( height ) )
    // space O( 1 )
    int maxArea(vector<int>& height)
    {
        if( height.empty() )
            return 0;

        int l = 0;
        int r = height.size() - 1;
        int max_volume{ 0 };
        while( l < r ) {
            auto h = std::min( height[ l ], height[ r ] );
            auto volume = h * ( r - l );
            max_volume = std::max( max_volume, volume );
            if( height[ l ] <= height[ r ] ) {
                ++l;
            } else {
                --r;
            }
        }
        
        return max_volume;
    }
};
