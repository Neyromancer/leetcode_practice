ass Solution {
public:
    // time O( sizeof( nums ) )
    // space O( 1 )
    int longestOnes(vector<int>& nums, int k)
    {
        int len{ 0 };
        int l{ 0 };
        int r{ 0 };
        int sz = nums.size();
        while( r < sz ) {
            while( r < sz && !nums[ r ] && k > 0 ) {
                --k;
                ++r;
            }
            
            len = std::max( len, r - l );
            while( l <= r && r < sz && !nums[ r ] && k <= 0 ) {
                if( !nums[ l ] )
                    ++k;
                
                ++l;
            }
            
            if( r < sz && nums[ r ] )
                ++r;
        }
        
        return std::max( len, r - l );
    }
};
