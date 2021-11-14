class UnionFind {
    std::vector<int> ranks;
    std::vector<int> roots;
    int nodes{ 0 };
    int timestamp{ -1 };
    
public:
    UnionFind( int size ) {
        nodes = size;
        ranks.resize( size );
        roots.resize( size );
        for( int i = 0; i < size; ++i ) {
            roots[ i ] = i;
            ranks[ i ] = 1;
        }
    }
    
    int find( int x ) {
        while( x == roots[ x ] )
            return x;
        return roots[ x ] = find( roots[ x ] );
    }
    
    void unite( int x, int y, int time ) {
        int root_x = find( x );
        int root_y = find( y );

        if( root_x == root_y )
            return;
        
        --nodes;
        if( ranks[ root_x ] > ranks[ root_y ] )
            roots[ root_y ] = root_x;
        else if( ranks[ root_y ] > ranks[ root_x ] )
            roots[ root_x ] = root_y;
        else {
            roots[ root_y ] = root_x;
            ++ranks[ root_x ];
        }

        timestamp = time;
    }
    
    int get_root_num() {
        return nodes;
    }
    
    int get_timestamp() {
        return timestamp;
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n)
    {
        std::sort( std::begin( logs ), std::end( logs ), []( auto log1, auto log2 ){
            return log1[ 0 ] < log2[ 0 ];
        } );
        
        UnionFind uf{ n };
        for( int i = 0; i < logs.size(); ++i ) {
            uf.unite( logs[ i ][ 1 ], logs[ i ][ 2 ], logs[ i ][ 0 ] );
        }
        
        if( uf.get_root_num() > 1 )
            return -1;

        return uf.get_timestamp();
    }
};
