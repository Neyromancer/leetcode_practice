class UnionFind {
    std::vector<int> m_roots;
    std::vector<int> m_ranks;
    int m_max_area{ 0 };

public:
    UnionFind( int xsize, int ysize )
    {
        m_roots.resize( ( xsize + 1 ) * ysize );
        m_ranks.resize( m_roots.size() );
        for( int i = 0; i < m_roots.size(); ++i ) {
            m_roots[ i ] = i;
            m_ranks[ i ] = 1;
        }
    }
    
    int find( int x )
    {
        if( x == m_roots[ x ] )
            return x;
        return m_roots[ x ] = find( m_roots[ x ] );
    }
    
    void unite( int x, int y )
    {
        int rootX = find( x );
        int rootY = find( y );
        if( rootX == rootY ) {
            m_max_area = std::max( { m_max_area, m_ranks[ rootY ], m_ranks[ rootX ] } );
            return;
        }
       
        if( m_ranks[ rootX ] >= m_ranks[ rootY ] ) {
            m_roots[ rootY ] = rootX;
            m_ranks[ rootX ] += m_ranks[ rootY ];
        } else if( m_ranks[ rootX ] < m_ranks[ rootY ] ) {
            m_roots[ rootX ] = rootY;
            m_ranks[ rootY ] += m_ranks[ rootX ];           
        }

        m_max_area = std::max( { m_max_area, m_ranks[ rootY ], m_ranks[ rootX ] } );
    }
    
    bool is_connected( int x, int y )
    {
        return find( x ) == find( y );
    }
    
    int max_area()
    {
        return m_max_area;
    }
};

class Solution {
    int m_hsize{ 0 };
    int m_vsize{ 0 };
public:
    int transform( int y, int x )
    {
        return y * m_hsize + x;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        if( grid.empty() )
            return 0;
        
        UnionFind uf{ static_cast<int>( grid.front().size() ), 
                     static_cast<int>( grid.size() ) };
        m_hsize = grid.front().size();
        m_vsize = grid.size();
        for( int i = 0; i < grid.size(); ++i ) {
            for( int j = 0; j < grid.front().size(); ++j ) {
                if( grid[ i ][ j ] ) {
                    uf.unite( transform( i, j ), transform( i, j ) );
                    if( i > 0 && grid[ i - 1 ][ j ] )
                        uf.unite( transform( i, j ),
                                  transform( i - 1, j ) );

                    if( j > 0 && grid[ i ][ j - 1 ] )
                        uf.unite( transform( i, j ),
                                  transform( i, j - 1 ) );
                    
                    if( ( i + 1 ) < grid.size() && grid[ i + 1 ][ j ] )
                        uf.unite( transform( i, j ),
                                  transform( i + 1, j ) );

                    if( ( j + 1 ) < grid.front().size() && grid[ i ][ j + 1 ] )
                        uf.unite( transform( i, j ),
                                  transform( i, j + 1 ) );
                }
            }
        }
        
        return uf.max_area();
    }
};
