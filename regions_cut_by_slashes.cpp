// DFS
class Solution {
public:
    // [" /","/ "]
    // space O( N^2 )
    // time O( N^2 * 9 N^2 )
    int regionsBySlashes(vector<string>& grid) {
        std::vector<std::vector<bool>> st( grid.size() * 3, std::vector<bool>( grid.size() * 3 ) );
        for( int i = 0; i < grid.size(); ++i ) {
            for( int j = 0; j < grid.front().size(); ++j ) {
                if( grid[ i ][ j ] == '\\' ) { // O( 1 )
                    st[ i * 3 ][ j * 3 ] = true; // O( 1 )
                    st[ i * 3 + 1 ][ j * 3 + 1 ] = true;
                    st[ i * 3 + 2 ][ j * 3 + 2 ] = true;
                 } else if( grid[ i ][ j ] == '/' ) {
                    st[ i * 3 ][ j * 3 + 2 ] = true;
                    st[ i * 3 + 1 ][ j * 3 + 1 ] = true;
                    st[ i * 3 + 2 ][ j * 3 ] = true;
                }
            }
        }
        
        int regions{ 0 };
        for( int i = 0; i < st.size(); ++i ) {
            for( int j = 0; j < st.front().size(); ++j ) {
                if( !st[ i ][ j ] ) {
                    dfs( st, i, j );
                    ++regions;
                }
            }
        }
        
        return regions;
    }
    
    void dfs( std::vector<std::vector<bool>> &grid, int i, int j )
    {
        if( i < 0 || j < 0 )
            return;
        
        if( i >= grid.size() || j >= grid.front().size() ) // O( 1 )
            return;
        
        if( grid[ i ][ j ] ) // O( 1 )
            return;
        
        grid[ i ][ j ] = true; // O( 1 )
        dfs( grid, i, j + 1 );
        dfs( grid, i, j - 1 );
        dfs( grid, i + 1, j );
        dfs( grid, i - 1, j );
    }
};


// Union Find
cass Solution {
    class UnionFind {
        int size{ 0 };
        int count{ 0 };
        std::vector<int> parents;
    public:
        UnionFind( int sz )
        {
            size = sz;
            count = size * size * 4;
            parents.resize( count );
            for( int i = 0; i < parents.size(); ++i )
                parents[ i ] = i;
        }
        
        void unite( int i, int j )
        {
            int pi = find_root( i );
            int pj = find_root( j );
            if( pi == pj )
                return;
            
            parents[ pi ] = pj;
            --count;
        }
        
        int find_root( int i )
        {
            while( i != parents[ i ] )
                i = parents[ i ];
            
            return i;
        }
        
        int g( int i, int j, int k )
        {
            return ( i * size + j ) * 4 + k;
        }
        
        int regions()
        {
            return count;
        }
    };
public:
    int regionsBySlashes(vector<string>& grid)
    {
        UnionFind uf( grid.size() );
        for( int i = 0; i < grid.size(); ++i ) {
            for( int j = 0; j < grid.size(); ++j ) {
                if( i > 0 )
                    uf.unite( uf.g( i - 1, j, 2 ), uf.g( i, j, 0 ) );
                
                if( j > 0 )
                    uf.unite( uf.g( i, j - 1, 1 ), uf.g( i, j, 3 ) );
                
                if( grid[ i ][ j ] != '/' ) {
                    uf.unite( uf.g( i, j, 0 ), uf.g( i, j, 1 ) );
                    uf.unite( uf.g( i, j, 3 ), uf.g( i, j, 2 ) );
                } 
                if( grid[ i ][ j ] != '\\' ) {
                    uf.unite( uf.g( i, j, 3 ), uf.g( i, j, 0 ) );
                    uf.unite( uf.g( i, j, 1 ), uf.g( i, j, 2 ) );
                }
            }
        }
        
        return uf.regions();
    }
};
