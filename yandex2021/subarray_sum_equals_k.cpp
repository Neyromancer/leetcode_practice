class Solution {
public:
    // time O( N ), where N == nums.size
    // space O( N ), where N == nums.size
    int subarraySum(vector<int>& nums, int k)
    {
        std::unordered_map<int,int> st {{0, 1}};
        int sum{ 0 };
        int res{ 0 };
        for( int i = 0; i < nums.size(); ++i ) {
            sum += nums[ i ];
            if( st.count( sum - k ) )
                res += st[ sum - k ];
            ++st[ sum ];
        }
        
        return res;
    }
};
