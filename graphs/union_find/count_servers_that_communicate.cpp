class UF {
    std::vector<int> roots;
    std::vector<int> ranks;

public:
    UF( int size ) {
        roots.resize( size );
        std::iota( std::begin( roots ), std::end( roots ), 0 );
        ranks.resize( size, 1 );
    }
    
    int find( int x ) {
        if( x == roots[ x ] )
            return x;
        return find( roots[ x ] );
    }
    
    void unite( int x, int y ) {
        auto xroot = find( x );
        auto yroot = find( y );
        if( yroot == xroot )
            return;
        
        if( ranks[ xroot ] >= ranks[ yroot ] ) {
            ranks[ xroot ] += ranks[ yroot ];
            roots[ yroot ] = xroot;
        } else {
            ranks[ yroot ] += ranks[ xroot ];
            roots[ xroot ] = yroot;            
        }
    }
    
    bool combined( int x, int y ) {
        return find( x ) == find( y );
    }
    
};

class Solution {
public:
    int countServers( vector<vector<int>>& grid )
    {
        int h = grid.size();
        int w = grid.front().size();
        UF uf( h * w );
        auto point = [w]( int y, int x ) -> int {
            return y * w + x;
        };
        
        for( int i = 0; i < grid.size(); ++i ) {
            int ptr = -1;
            for( int j = 0; j < grid.front().size(); ++j ) {
                if( grid[ i ][ j ] ) {
                    if( ptr < 0 ) {
                        ptr = point( i, j );
                    } else {
                        uf.unite( ptr, point( i, j ) );
                    }
                }
            }
        }

        for( int i = 0; i < grid.front().size(); ++i ) {
            int ptr = -1;
            for( int j = 0; j < grid.size(); ++j ) {
                if( grid[ j ][ i ] ) {
                    if( ptr < 0 ) {
                        ptr = point( j, i );
                    } else {
                        uf.unite( ptr, point( j, i ) );
                    }
                }
            }
        }
        
        std::unordered_map<int, int> group;
        for( int i = 0; i < grid.size(); ++i ) {
            for( int j = 0; j < grid.front().size(); ++j ) {
                if( grid[ i ][ j ] )
                    ++group[ uf.find( point( i, j ) ) ];
            }
        }
        
        int res{ 0 };
        for( const auto&[ root, cnt ] : group ) {
            if( cnt > 1 )
                res += cnt;
        }
        
        return res;
    }
};
