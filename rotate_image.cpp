class Solution {
public:
    // time O( matrix.size() ^ 2 )
    // space O( 1 )
    void rotate(vector<vector<int>>& matrix) 
    {
        int l{ 0 };
        int r = matrix.size() - 1; // O( 1 )
        while( l < r ) { // O( matrix.size() )
            int j = 0;
            while( j + l < r ) { // O( matrix.size() )
                auto val = matrix[ matrix.size() - r - 1 ][ l + j ]; // O( 1 )
                std::swap( val, matrix[ l + j ][ r ] ); // O( 1 )
                std::swap( val, matrix[ r ][ r - j ] ); // O( 1 ) 
                std::swap( val, matrix[ r - j ][ matrix.size() - r - 1 ] ); // O( 1 )
                std::swap( val, matrix[ matrix.size() - r - 1 ][ l + j ] ); // O( 1 )
                ++j;
            }
            
            --r;
            ++l;
        }
    }
};
