class Solution {
public:
    // time O( N ), N == nums.size()
    // space O( 1 )
    vector<string> summaryRanges(vector<int>& nums)
    {
        if( nums.empty() )
            return {};

        std::vector<std::string> res;
        int i{ 0 };
        while( i < nums.size() ) {
            int var = nums[ i ];
            int j = i + 1;
            while( j < nums.size() && var + 1 == nums[ j ] ) {
                ++var;
                ++j;
            }
            
            std::string tmp = std::to_string( nums[ i ] );
            if( var != nums[ i ] )
                tmp += "->" + std::to_string( var );
            
            res.push_back( tmp );
            i = j;
        }
        
        return res;
    }
};


