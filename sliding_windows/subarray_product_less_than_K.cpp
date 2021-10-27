class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        if( k <= 1 )
            return 0;

        std::size_t product{ 1 };
        std::size_t l{ 0 };
        std::size_t r{ 0 };
        int cnt{ 0 };
        while( r < nums.size() ) {
            product *= nums[ r ];
            if( product >= k ) {
                while( l <= r && product >= k )
                    product /= nums[ l++ ];
            }

            cnt += r - l + 1;
            ++r;
        }
        
        return cnt;
    }
};
