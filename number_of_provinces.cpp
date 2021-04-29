// dfs implementation
class Solution {
public:
    // space O( N ), where N is the size of isConnected
    // time O( N^2 ), where N is the size of isConnected
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        std::vector<bool> st( isConnected.size() );
        int cnt{ 0 }; // 0
        for( int i = 0; i < isConnected.size(); ++i ) {
            if( !st[ i ] ) { //
                dfs( isConnected, st, i ); //
                ++cnt;
            }
        }

        return cnt;
    }

    void dfs( const std::vector<std::vector<int>> &grid, std::vector<bool> &st, int i ) // 0 0 3 2
    {
        for( int j = 0; j < st.size(); ++j ) { // 1
            if( grid[ i ][ j ] == 1 && !st[ j ] ) {
                st[ j ] = true;
                dfs( grid, st, j );
            }
        }
    }
};

// time O( N^2 ), where N == isConnected.size()
// space O( N ), where N == isConnected.size()
class Solution {
public:
    /*      0 1 2
        0 [[0,1,0],
        1  [1,0,0],
        2  [0,0,0]]
    */
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int cnt{ 0 }; // 2
        for( int i = 0; i < isConnected.size(); ++i ) {
            if( isConnected[ i ][ i ] ) { // 2
                dfs( isConnected, i );
                ++cnt;
            }
        }
        
        return cnt;
    }
    
    void dfs( std::vector<std::vector<int>> &grid, int i ) { //
        grid[ i ][ i ] = 0;
        for( int j = 0; j < grid.size(); ++j ) { //
            if( grid[ j ][ j ] && grid[ i ][ j ] ) {
                dfs( grid, j );
            }
        }
    }
};

// Unoin Find
class Solution {
    class UnionFind {
        int count{ 0 };
        std::vector<int> parents;
        std::vector<int> ranks;
    public:
        UnionFind( int n )
        {
            count = n;
            parents.resize( n );
            ranks.resize( n );
            std::fill( std::begin( ranks ), std::end( ranks ), 1 );
            for( int i = 0; i < n; ++i )
                parents[ i ] = i;
        }
        
        int find_root( int v )
        {
            while( v != parents[ v ] )
                v = parents[ v ];
            
            return v;
        }
        
        void unite( int p, int q )
        {
            int pid = find_root( p );
            int qid = find_root( q );
            if( pid == qid )
                return;
            
            if( ranks[ pid ] > ranks[ qid ] ) {
                ranks[ pid ] += ranks[ qid ];
                parents[ pid ] = qid;
            } else {
                ranks[ qid ] += ranks[ pid ];
                parents[ qid ] = pid;                
            }
            
            --count;
        }
        
        int size() {
            return count;
        }
    };
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        UnionFind uf( size );
        for( int i = 0; i < isConnected.size(); ++i ) {
            for( int j = 0; j < isConnected.size(); ++j ) {
                if( isConnected[ i ][ j ] )
                    uf.unite( i, j );
            }
        }
        
        return uf.size();
    }
};
