class Solution {
public:
    // space O( N ), where N == nums.szie()
    // time O( N ), where N == nums.size()
    vector<int> productExceptSelf(vector<int>& nums)
    {
        auto nums1 = nums;
        int mem{ 1 };
        for( int i = 1; i < nums.size(); ++i ) {
            auto tmp = nums[ i ];
            nums[ i ] = nums[ i - 1 ] * mem;
            mem = tmp;
        }
        nums[ 0 ] = 1;

        mem = 1;
        for( int i = nums1.size() - 2; i >= 0; --i ) {
            auto tmp = nums1[ i ];
            nums1[ i ] = nums1[ i + 1 ] * mem;
            mem = tmp;
        }
        nums1[ nums.size() - 1 ] = 1;
   
        for( int i = 0; i < nums.size(); ++i )
            nums[ i ] *= nums1[ i ];
        
        return nums;
    }
};
