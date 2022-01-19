// Bottom-up implementation
class Solution {
public:
    // TC: O( sizeof( nums ) )
    // SC: O( 1 )
    int rob(vector<int>& nums)
    {
        if( nums.size() == 1 )
            return nums.front();
        
        if( nums.size() == 2 )
            return std::max( nums[ 0 ], nums[ 1 ] );
        
        nums[ 2 ] += nums[ 0 ];
        int sz = nums.size();
        for( int i = 3; i < sz; ++i )
            nums[ i ] += std::max( nums[ i - 2 ], nums[ i - 3 ] );
        
        return std::max( nums[ sz - 1 ], nums[ sz - 2 ] );
    }
};

// Top-down implementation
class Solution {
public:
    // TC: O( sizeof( nums ) )
    // SC: O( sizeof( nums ) )
    int rob(vector<int>& nums)
    {
        if( nums.size() == 1 )
            return nums.front();
        
        if( nums.size() == 2 )
            return std::max( nums[ 0 ], nums[ 1 ] );
        
        nums[ 2 ] += nums[ 0 ];
        check_houses( nums, 3 );
        return std::max( nums[ nums.size() - 1 ], nums[ nums.size() - 2 ] );
    }
    
    void check_houses( std::vector<int>& nums, int i ) {
        if( i >= nums.size() )
            return;
        
        nums[ i ] += std::max( nums[ i - 2 ], nums[ i - 3 ] );
        check_houses( nums, i + 1 );
    }
};

