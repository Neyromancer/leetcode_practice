class UnionFind {
    std::vector<int> ranks;
    std::vector<int> roots;
    int nodes{ 0 };
    
public:
    UnionFind( int size ) {
        ranks.resize( size );
        roots.resize( size );
        for( int i = 0; i < size; ++i ) {
            ranks[ i ] = 1;
            roots[ i ] = i;
        }
        
        nodes = size;
    }
    
    int find( int x ) {
        if( x == roots[ x ] )
            return x;
        return roots[ x ] = find( roots[ x ] );
    }
    
    void unite( int x, int y ) {
        int root_x = find( x );
        int root_y = find( y );
        if( root_x == root_y )
            return;
        
        if( ranks[ root_y ] > ranks[ root_x ] )
            roots[ root_x ] = root_y;
        else if( ranks[ root_x ] > ranks[ root_y ] )
            roots[ root_y ] = root_x;
        else {
            roots[ root_y ] = root_x;
            ++ranks[ root_x ];
        }
        
        --nodes;
    }
    
    bool connected( int x, int y ) {
        return find( x ) == find( y );
    }
    
    int get_root_num() {
        return nodes;
    }
};
class Solution {
public:
    // time O( n )
    // space O( n )
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf{ n }; // O( n )
        for( int i = 0; i < edges.size(); ++i ) { // O( edges.size() )
            uf.unite( edges[ i ][ 0 ], edges[ i ][ 1 ] ); // O( 1 )
        }
        
        return uf.get_root_num(); // O( 1 )
    }
};
