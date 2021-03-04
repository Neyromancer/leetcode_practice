// space O( 1 )
// time O( log N )
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if( nums.empty() )
            return {-1, -1};

        std::vector<int> ans{-1,-1};
        int l{ 0 };
        int r = nums.size() - 1;
        int index{ -1 };
        while( l <= r ) {
            int mid = l + ( r - l ) / 2;
            if( nums[ mid ] >= target ) {
                r = mid - 1;
                if( nums[ mid ] == target )
                    index = mid;
            } else
                l = mid + 1;
        }
        
        ans[ 0 ] = index;
        l = 0;
        r = nums.size() - 1;
        index = -1;
        while( l <= r ) {
            int mid = l + ( r - l ) / 2;
            if( nums[ mid ] > target ) {
                r = mid - 1;
            } else {
                l = mid + 1;
                if( nums[ mid ] == target )
                    index = mid;
            }
        }
        ans[ 1 ] = index;
        
        return ans;
    }
};
