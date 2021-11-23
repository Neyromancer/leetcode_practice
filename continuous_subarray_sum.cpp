    bool checkSubarraySum(vector<int>& nums, int k) {        
        for( int i = 1; i < nums.size(); ++i )            
            nums[ i ] += nums[ i - 1 ];
        
        std::unordered_map<int, int> st;
        st[ 0 ] = -1;
        for( int i = 0; i < nums.size(); ++i ) {
            auto remainder = nums[ i ] % k;
            if( st.count( remainder ) ) {
                if( ( i - st[ remainder ] >= 2 ) )
                    return true;
            } else {
                st[ remainder ] = i;
            }
        }
        
        return false;
    }
}
