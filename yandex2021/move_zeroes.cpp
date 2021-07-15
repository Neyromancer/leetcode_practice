class Solution {
public:
    /**
        [1,3,4,0,5,0,7]
        [0,1,0,3,12]
    */
    // time O( N ), N == sizeof( nums )
    // space O( 1 )
    void moveZeroes( vector<int>& nums )
    {
        int j{ 0 };
        for( int i = 0; i < nums.size(); ++i ) {
            if( !nums[ j ] && nums[ i ] )
                std::swap( nums[ j ], nums[ i ] );            
            
            if( nums[ j ] )
                ++j;
        }
    }
};
