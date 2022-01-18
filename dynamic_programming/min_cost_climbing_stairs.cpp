// Top-Down implementation
class Solution {
public:
    // TC: O( cost.size() )
    // SC: O( cost.size() )
    int minCostClimbingStairs(vector<int>& cost)
    {
        if( cost.empty() )
            return 0;
        
        if( cost.size() == 1 )
            return cost[ 0 ];
        
        if( cost.size() == 2 )
            return std::min( cost[ 0 ], cost[ 1 ] );
        
        cost.resize( cost.size() + 1 );
        return calc_cost( cost, 2 );
    }
    
    int calc_cost( std::vector<int>& cost, int i ) {
        if( i >= cost.size() )
            return cost.back();
        
        cost[ i ] += std::min( cost[ i - 1 ], cost[ i - 2 ] );
        return calc_cost( cost, i + 1 );
    }
};


// Bottom-Up implementation
class Solution {
public:
    // TC O( cost.size() )
    // SC O( cost.size() )
    int minCostClimbingStairs(vector<int>& cost)
    {
        if( cost.size() == 2 )
            return std::min( cost[ 0 ], cost[ 1 ] );
        
        cost.resize( cost.size() + 1 );
        for( int i = 2; i < cost.size(); ++i ) {
            cost[ i ] += std::min(cost[ i - 1 ], cost[ i - 2 ]);
        }
        
        return cost.back();
    }
};
