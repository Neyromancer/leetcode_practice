class Solution {
    std::unordered_set<int> cache;
public:
    // SC: O( nums.size() )
    // TC: O( nums.size() )
    bool canPartition(vector<int>& nums) 
    {
        auto total_sum = std::accumulate( std::begin( nums ), std::end( nums ), 0 );
        if( total_sum % 2 != 0 )
            return false;
        
        auto part_sum = total_sum / 2;
        return canPartition( nums, part_sum - nums[ 0 ], 0 );
    }
    
    bool canPartition(const vector<int>& nums, int partSum, int index ) {
        if( partSum == 0 )
            return true;
        
        if( partSum < 0 )
            return false;
        
        if( index + 1 >= nums.size() )
            return false;
        
        if( cache.count( partSum ) )
            return false;
        
        cache.insert( partSum );
        
        for( int i = index + 1; i < nums.size(); ++i )
            if( canPartition( nums, partSum - nums[ i ], i ) || canPartition( nums, partSum, i ) )
                return true;
        return false;
    }
};

class Solution {
public:
    // TC: O( sumof( nums ) * sizeof( nums ) )
    // SC: O( sumof( nums ) * sizeof( nums ) )
    bool canPartition(vector<int>& nums) {
        int tsum = std::accumulate( std::begin( nums ), std::end( nums ), 0 );
        if( tsum % 2 )
            return false;
        
        int target = tsum / 2;
        int sz = nums.size();
        std::vector<std::vector<bool>> st( sz + 1, std::vector<bool>( target + 1 ) );
        
        for( int i = 0; i < st.size(); ++i ) {
            st[ i ][ 0 ] = true;
        }
        
        for( int i = 1; i <= sz; ++i ) {
            int curr = nums[ i - 1 ];
            for( int j = 0; j <= target; ++j ) {
                if( curr > j ) {
                    st[ i ][ j ] = st[ i - 1 ][ j ];
                } else {
                    st[ i ][ j ] = st[ i - 1 ][ j ] || st[ i - 1 ][ j - curr ];
                }
            }
        }

        return st[ sz ][ target ];
    }
};
