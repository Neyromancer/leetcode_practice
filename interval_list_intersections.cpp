/***
[[0,2],[5,10],[13,23],[24,25]]
[[1,5],[8,12],[15,24],[25,26]]
[[1,3],[5,9]]
[]
[]
[[4,8],[10,12]]
[[1,7]]
[[3,10]]
[[4,11]]
[[1,2],[8,11],[12,13],[14,15],[17,19]]

*/
class Solution {
public:
    //       |
    // A: [[4,11]]
    //       0
    // B: [[1,2],[8,11],[12,13],[14,15],[17,19]]
    //                     |
    //res:[[8,11]]
    // space O( A.size() + B.size() )
    // time O( A.size() + B.size() )
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B)
    {
        int ia{ 0 }; // 0
        int ib{ 0 }; // 2
        vector<vector<int>> res;
        while( ia < A.size() && ib < B.size() ) {
            std::vector<int> tmp;
            if( B[ ib ][ 0 ] >= A[ ia ][ 0 ] && B[ ib ][ 0 ] <= A[ ia ][ 1 ] ) {
                tmp.push_back( B[ ib ][ 0 ] );
                if( B[ ib ][ 1 ] <= A[ ia ][ 1 ] ) {
                    tmp.push_back( B[ ib ][ 1 ] );
                    ++ib;
                } else {
                    tmp.push_back( A[ ia ][ 1 ] );
                    ++ia;
                }
            } else if( B[ ib ][ 0 ] < A[ ia ][ 0 ] ) {
                if( B[ ib ][ 1 ] >= A[ ia ][ 1 ] ) {
                    tmp.push_back( A[ ia ][ 0 ] );
                    tmp.push_back( A[ ia ][ 1 ] );
                    ++ia;
                } else if( B[ ib ][ 1 ] >= A[ ia ][ 0 ] ) {
                    tmp.push_back( A[ ia ][ 0 ] );
                    tmp.push_back( B[ ib ][ 1 ] );
                    ++ib;
                } else {
                 // ++ia;
                 ++ib;
                }
            } else 
                ++ia;
            
            if( !tmp.empty() )
                res.push_back( tmp );
        }
        
        return res;
    }
};

/***
[[0,2],[5,10],[13,23],[24,25]]
[[1,5],[8,12],[15,24],[25,26]]
[[1,3],[5,9]]
[]
[]
[[4,8],[10,12]]
[[1,7]]
[[3,10]]
[[4,11]]
[[1,2],[8,11],[12,13],[14,15],[17,19]]

*/
class Solution {
public:
    // space O( A.size() + B.size() )
    // time O( A.size() + B.size() )
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B)
    {
        int ia{ 0 };
        int ib{ 0 };
        vector<vector<int>> res;
        while( ia < A.size() && ib < B.size() ) {
            auto lo = std::max( A[ ia ][ 0 ], B[ ib ][ 0 ] );
            auto hi = std::min( A[ ia ][ 1 ], B[ ib ][ 1 ] );

            if( lo <= hi )
                res.push_back( { lo, hi } );
            
            if( A[ ia ][ 1 ] <= B[ ib ][ 1 ] )
                ++ia;
            else
                ++ib;
        }
        
        return res;
    }
};
