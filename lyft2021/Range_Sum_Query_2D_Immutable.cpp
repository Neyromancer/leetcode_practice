class NumMatrix {
    std::vector<std::vector<int>> mem;
public:
    // time O( N x M )
    // space O( N x M )
    NumMatrix( vector<vector<int>>& matrix )
    {
        mem.resize( matrix.size() + 1 );
        for( int i = 0; i < mem.size(); ++i )
            mem[ i ].resize( matrix.front().size() + 1 );
        
        for( int i = 1; i < mem.size(); ++i ) {
            for( int j = 1; j < mem.front().size(); ++j ) {
                mem[ i ][ j ] = matrix[ i - 1 ][ j - 1 ] + mem[ i ][ j - 1 ] +
                    mem[ i - 1 ][ j ] - mem[ i - 1 ][ j - 1 ];
            }
        }
    }
    
    // time O( 1 )
    // space O( 1 )
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        ++row1;
        ++col1;
        ++row2;
        ++col2;
        return mem[ row2 ][ col2 ] - mem[ row2 ][ col1 - 1 ] - mem[ row1 - 1 ][ col2 ] + mem[ row1 - 1 ][ col1 - 1 ];
        // return 0;
    }
};
