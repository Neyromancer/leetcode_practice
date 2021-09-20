class Solution {
public:
    // space O( 1 )
    // time O( sizeof( nums ))
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int l{ 0 };
        bool is_zero{ false };
        int len{ 0 };
        for( int r = 0; r < static_cast<int>( nums.size() ); ++r ) {
            if( !nums[ r ] ) {
                while( l < r && is_zero ) {
                    if( !nums[ l++ ] )
                        is_zero = false;
                }
                
                is_zero = true;
            }
            
            len = std::max( len, r - l + 1 );
        }
        
        return len;
    }
};
