class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for( int i = 0; i < matrix.size(); ++i ) {
            if( bsearch( matrix[ i ], target ) )
                return true;
        }
        
        return false;
    }
    
    bool bsearch( const std::vector<int> &vc, int val )
    {
        int l = 0;
        int r = vc.size() - 1;
        while( l <= r ) {
            int mid = l + ( r - l ) / 2;
            if( vc[ mid ] == val )
                return true;
            else if( vc[ mid ] < val )
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        return false;
    }
};

//////////////////////////////////////////////////////////////////
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if( matrix.empty() || matrix.front().empty() )
            return false;
        
        int r = 0;
        int c = matrix[ 0 ].size() - 1;
        while( r < matrix.size() && c >= 0 ) {
            int val = matrix[ r ][ c ];
            if( val == target )
                return true;
            else if( val < target )
                ++r;
            else
                --c;
        }
        
        return false;
    }
};
