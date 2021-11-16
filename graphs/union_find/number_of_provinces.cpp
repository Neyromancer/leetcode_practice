class UnionFind {
    std::vector<int> m_roots;
    std::vector<int> m_ranks;
    int m_size{ 0 };
    
public:
    UnionFind( int size )
    {
        m_size = size;
        m_roots.resize( m_size );
        m_ranks.resize( m_size );
        for( int i = 0; i < size; ++i ) {
            m_roots[ i ] = i;
            m_ranks[ i ] = 1;
        }
    }
    // time O( alph( N ) ), where N is the number of requests and alph is the inverse Akerman function
    // in practice O( alph( N ) ) == O( 1 )
    // space O( 1 )
    int find( int x )
    {
        if( x == m_roots[ x ] )
            return x;
        return m_roots[ x ] = find( m_roots[ x ] );
    }
    
    // time O( alph( N ) ), where N is the number of requests and alph is the inverse Akerman function
    // in practice O( alph( N ) ) == O( 1 )
    // space O( 1 )
    void unite( int x, int y )
    {
        int rootX = find( x );
        int rootY = find( y );
        if( rootY == rootX )
            return;
        
        if( m_ranks[ rootX ] > m_ranks[ rootY ] ) {
            m_roots[ rootY ] = rootX;
        } else if( m_ranks[ rootX ] < m_ranks[ rootY ] ) {
            m_roots[ rootX ] = rootY;
        } else {
            m_roots[ rootY ] = rootX;
            m_ranks[ rootX ] += 1;
        }
        
        --m_size;
    }
    
    int provinces()
    {
        return m_size;
    }
    
    bool is_connected( int x, int y )
    {
        return find( x ) == find( y );
    }
};

class Solution {
public:
    
    // time O( N * M ), where N == sizeof( isConnected ) and M == sizeof( isConnected[ 1 ] )
    // space O( 1 )
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        UnionFind uf{ static_cast<int>( isConnected.size() ) };
        for( int i = 0; i < isConnected.size(); ++i ) {
            for( int j = 0; j < isConnected[ i ].size(); ++j ) {
                if( isConnected[ i ][ j ] )
                    uf.unite( i, j );
            }
        }
        
        return uf.provinces();
    }
};
