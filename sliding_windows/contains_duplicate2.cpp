class Solution {
public:
    // time O( sizeof( nums ) )
    // space O( min( sizeof( n ), k ) )
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        if( nums.empty() || !k )
            return false;
        
        std::unordered_set<int> st;
        int l{ 0 };
        for( int r = 0; r < nums.size(); ++r ) {
            if( st.count( nums[ r ] ) )
                return true;
            
            st.insert( nums[ r ] );
            while( l <= r && st.size() > k )
                st.erase( nums[ l++ ] );
        }
        
        return false;
    }
};


