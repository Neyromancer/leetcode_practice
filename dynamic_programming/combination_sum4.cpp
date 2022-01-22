// Top-down implementation
class Solution {
    std::unordered_map<int, int> dp;
public:
    // TC: O( T * N ), where T is the target and N == nums.size()
    // SC: O( N ), T is target
    int combinationSum4(vector<int>& nums, int target) {
        if( !target )
            return 1;
        
        if( target < 0 )
            return 0;
        
        if( dp.count( target ) )
            return dp[ target ];
        
        for( int n : nums )
            dp[ target ] += combinationSum4(nums, target - n );
        return dp[ target ];
    }
};

// Bottom-Up approach
class Solution {
public:
    // TC: O( target * nums.size() )
    // SC: O( target )
    int combinationSum4(vector<int>& nums, int target) {
        std::vector<std::uint64_t> dp( target + 1 );
        dp[ 0 ] = 1;
        for( int t = 1; t < dp.size(); ++t ) {
            for( int n : nums ) {
                if( t - n >= 0 )
                    dp[ t ] += dp[ t - n ];
            }
        }
        
        return dp[ target ];
    }
};
