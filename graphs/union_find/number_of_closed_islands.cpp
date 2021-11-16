class UnionFind {
    std::vector<int> roots;
    std::vector<int> ranks;
    
public:
    UnionFind( const std::vector<std::vector<int>> &grid )
    {
        roots.resize( grid.size() * ( grid.front().size() + 1 ) );
        ranks.resize( roots.size() );
        for( int i = 0; i < roots.size(); ++i ) {
            roots[ i ] = i;
            ranks[ i ] = 1;
        }
    }

    // time O( 1 )
    int find( int x )
    {
        if( x == roots[ x ] )
            return x;
        return roots[ x ] = find( roots[ x ] );
    }

    // time O( 1 )
    void unite( int x, int y )
    {
        int rootX = find( x );
        int rootY = find( y );
        if( rootX == rootY )
            return;

        if( ranks[ rootX ] > ranks[ rootY ] ) {
            roots[ rootY ] = rootX;
        } else if( ranks[ rootX ] < ranks[ rootY ] ) {
            roots[ rootX ] = rootY;
        } else {
            roots[ rootY ] = rootX;
            ++ranks[ rootX ];
        }
    }
    
    // time O( 1 )
    bool is_connected( int x, int y )
    {
        return find( x ) == find( y );
    }
};

class Solution {
    int hsize{ 0 };
public:
    // time O( N^2 x M^2 ), where N == g.size() and M == g.front().size()
    // space O( N x M ), where N == g.size() and M == g.front().size()
    int closedIsland(vector<vector<int>>& grid)
    {
        flood_islands( grid );
        hsize = grid.front().size();
        UnionFind uf{ grid };
        for( int i = 0; i < grid.size(); ++i ) {
            for( int j = 0; j < grid.front().size(); ++j ) {
                if( !grid[ i ][ j ] ) {
                    if( i > 0 && !grid[ i - 1 ][ j ] )
                        uf.unite( transform( i, j ), transform( i - 1, j ) );
                    
                    if( j > 0 && !grid[ i ][ j - 1 ] )
                        uf.unite( transform( i, j ), transform( i, j - 1 ) );
                    
                    if( ( i + 1 ) < grid.size() && !grid[ i + 1 ][ j ] )
                        uf.unite( transform( i, j ), transform( i + 1, j ) );
                    
                    if( ( j + 1 ) < grid.front().size() && !grid[ i ][ j + 1 ] )
                        uf.unite( transform( i, j ), transform( i, j + 1 ) );
                }
            }
        }
        
        std::unordered_set<int> roots;
        for( int i = 0; i < grid.size(); ++i ) {
            for( int j = 0; j < grid.front().size(); ++j ) {
                if( !grid[ i ][ j ] )
                    roots.insert( uf.find( transform( i, j ) ) );
            }
        }
        
        return roots.size();
    }
    
    // time O( N^2 x M^2 ), where N == g.size() and M == g.front().size()
    // space O( N x M ), where N == g.size() and M == g.front().size()
    void flood_islands( std::vector<std::vector<int>> &g )
    {
        for( int i = 0; i < g.size(); ++i ) {
            for( int j = 0; j < g.front().size(); ++j ) {
                if( !g[ i ][ j ] && is_onboard( g, i, j ) )
                    dfs( g, i, j );
            }
        }
    }
    
    bool is_onboard( const std::vector<std::vector<int>> &g, int i, int j )
    {
        if( !i || !j || i >= ( g.size() - 1 ) || j >= ( g.front().size() - 1 ) )
            return true;
        return false;
    }
    
    // time O( N x M ), where N == g.size() and M == g.front().size()
    // space O( N x M ), where N == g.size() and M == g.front().size()
    void dfs( std::vector<std::vector<int>> &g, int i, int j )
    {
        if( i < 0 || j < 0 || i >= g.size() || j >= g.front().size() )
            return;
        
        if( g[ i ][ j ] )
            return;
        
        g[ i ][ j ] = 1;
        dfs( g, i + 1, j );
        dfs( g, i - 1, j );
        dfs( g, i, j + 1 );
        dfs( g, i, j - 1 );
    }
    
    int transform( int y, int x )
    {
        return y * hsize + x;
    }
};
