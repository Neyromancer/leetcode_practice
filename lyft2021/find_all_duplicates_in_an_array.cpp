class Solution {
public:
    // time O( N ), where n == nums.size
    // space O( 1 )
    vector<int> findDuplicates(vector<int>& nums)
    {
        std::vector<int> res;
        for( int i = 0; i < nums.size(); ++i ) {
            if( nums[ std::abs( nums[ i ] ) - 1 ] < 0 )
                res.push_back( std::abs( nums[ i ] ) );
            
            auto &n = nums[ std::abs( nums[ i ] ) - 1 ];
            n = std::abs( n ) * -1;
        }
        
        return res;
    }
};
