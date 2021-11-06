class Solution {
public:
    // time O( sizeof( nums ) )
    // space O( sizeof( nums ) )
    vector<int> singleNumber(vector<int>& nums)
    {
        std::unordered_map<int,int> st;
        for( int n : nums )
            ++st[ n ];
        
        std::vector<int> res;
        res.reserve( 2 );
        for( auto&&[ k, v ] : st )
            if( v == 1 )
                res.push_back( std::move( k ) );
        
        return res;
    }
};
