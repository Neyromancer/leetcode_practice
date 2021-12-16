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
        int xroot = find( x );
        int yroot = find( y );
        if( yroot == xroot )
            return;

        roots[ yroot ] = xroot;
        ranks[ xroot ] += ranks[ yroot ];
    }
    
    bool are_connected( int x, int y ) {
        return find( x ) == find( y );
    }
    
};

class Solution {
public:
    // time O( n * n )
    // space O( n )
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        UF uf{ n };
        for( int i = 0; i < leftChild.size(); ++i ) {
            if( leftChild[ i ] >= 0 && ( uf.are_connected( i, leftChild[ i ] ) || 
                                       leftChild[ i ] != uf.find( leftChild[ i ] ) ) )
                return false;

            if( leftChild[ i ] >= 0 )
                uf.unite( i, leftChild[ i ] );

            if( rightChild[ i ] >= 0 && ( uf.are_connected( i, rightChild[ i ] ) || 
                                         rightChild[ i ] != uf.find( rightChild[ i ] ) ) )
               return false;

            if( rightChild[ i ] >= 0 )
                uf.unite( i, rightChild[ i ] );
        }
        
        std::unordered_set<int> roots;
        for( int i = 0; i < n; ++i ) {
            if( rightChild[ i ] >= 0 )
                roots.insert( uf.find( rightChild[ i ] ) );
            
            if( leftChild[ i ] >= 0 )
                roots.insert( uf.find( leftChild[ i ] ) );
        }
        
        return roots.size() <= 1;
    }
};
