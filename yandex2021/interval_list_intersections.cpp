class Solution {
public:
    // space O( 1 )
    // time O( N + M ), N == firstList.size and M == secondList.size
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, 
                                             vector<vector<int>>& secondList) 
    {
        int i{ 0 };
        int j{ 0 };
        std::vector<std::vector<int>> res;
        while( i < firstList.size() && j < secondList.size() ) {
            int lo = std::max( firstList[ i ][ 0 ], secondList[ j ][ 0 ] );
            int hi = std::min( firstList[ i ][ 1 ], secondList[ j ][ 1 ] );

            if( lo <= hi )
                res.push_back( { lo, hi } );
            
            if( firstList[ i ][ 1 ] < secondList[ j ][ 1 ] )
                ++i;
            else
                ++j;
        }
        
        return res;
    }
};
