// space O( 1 )
// time O( N^2 ), where N - chips.size
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips)
    {
        int cost{ INT_MAX };
        int i{ 0 };
        while( i < chips.size() ) {
            while( i + 1 < chips.size() && 
                   chips[ i ] == chips[ i + 1 ] )
                ++i;
            
            int lcost{ 0 };
            for( int j = 0; j < chips.size(); ++j )
                lcost += std::abs( chips[ i ] - chips[ j ] ) % 2;
            cost = std::min( lcost, cost );
            
            ++i;            
        }

        return cost;
    }
};

// O( N ), N position.size();
// O( 1 ),
class Solution {
public:
    bool is_even( int n )
    {
        return n % 2 == 0;
    }
    
    int minCostToMoveChips(vector<int>& position) 
    {
        int odd{ 0 };
        int even{ 0 };
        for( int i = 0; i < position.size(); ++i ) {
            if( is_even( position[ i ] ) )
                ++even;
            else
                ++odd;
        }

        return std::min( odd, even );
    }
};
