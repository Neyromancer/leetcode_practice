class Solution {
public:
    // TC: O( 2^( 2 * sizeof( nums ) ) )
    // SC: O( sizeof( nums ) ) )
    int findTargetSumWays(vector<int>& nums, int target) {
        if( nums.empty() )
            return 0;
        
        return cnt_ways( nums, target, 0, 0 );
    }
    
    int cnt_ways( const std::vector<int>& nums, int target, int i, int res ) {
        if( i >= nums.size() ) {
            if( res == target )
                return 1;
            return 0;
        }
        
        return cnt_ways( nums, target, i + 1, res + nums[ i ] ) + 
            cnt_ways( nums, target, i + 1, res - nums[ i ] );
    }
};

class Solution {
public:
    // TC: O( sizeof( nums ) )
    // SC: O( sizeof( nums ) )
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        
        std::unordered_map<std::string, int> st;
        return cnt_ways(st, nums, 0, target, 0);
    }

    // TC: O( sizeof( nums ) * sumof( nums ) )
    // SC: O( sizeof( nums ) )   
    int cnt_ways(std::unordered_map<std::string, int>& st, const std::vector<int>& nums, 
                 int i, int target, int sum ) {
        
        if( i >= nums.size() ) {
            if( sum == target ) // O( 1 )
                return 1;
            return 0;
        }
        
        auto key = std::to_string( i ) + "," + std::to_string(sum); // O( sizeof( i ) + sizeof( sum ) )
        if( st.count( key ) ) // O( 1 )
            return st[ key ]; // O( 1 )
        
        st[ key ] = cnt_ways( st, nums, i + 1, target, sum + nums[ i ] ) +
            cnt_ways( st, nums, i + 1, target, sum - nums[ i ] );
        return st[ key ]; // O( 1 )
    }
};
