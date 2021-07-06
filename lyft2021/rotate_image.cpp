class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        if( matrix.empty() )
            return;
        
        int sz = static_cast<int>( matrix.size() - 1 );
        int size = sz;
        for( int x = 0; x < sz; ++x ) {
            int ix = x;
            for( int y = ix; y < sz; ++y ) {
                int iy = y;
                int n{ 4 };
                int val = matrix[ ix ][ iy ];
                while( --n >= 0 ) {
                    swap( ix, iy, size );
                    std::swap( val, matrix[ ix ][ iy ] );
                }
            }
            sz--;
        }
    }
    
    void swap( int &x, int &y, int size )
    {
        auto tmp = x;
        x = y;
        y = size - tmp;
    }
};
