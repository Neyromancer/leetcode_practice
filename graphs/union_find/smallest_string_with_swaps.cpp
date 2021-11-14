class UnionFind {
    std::vector<int> ranks;
    std::vector<int> roots;
    
public:
    UnionFind( std::size_t size ) {
        ranks.resize( size );
        roots.resize( size );
        for( std::size_t i = 0; i < size; ++i ) {
            ranks[ i ] = 1;
            roots[ i ] = i;
        }
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
        
        if( ranks[ root_x ] > ranks[ root_y ] )
            roots[ root_y ] = root_x;
        else if( ranks[ root_y ] > ranks[ root_x ] )
            roots[ root_x ] = root_y;
        else {
            roots[ root_y ] = root_x;
            ++ranks[ root_x ];
        }
    }
    
    bool connected( int x, int y ) {
        return find( x ) == find( y );
    }
    
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
    {
        UnionFind uf{ s.size() };
        for( int i = 0; i < pairs.size(); ++i )
            uf.unite( pairs[ i ][ 0 ], pairs[ i ][ 1 ] );
        
        std::unordered_map<int, std::priority_queue<char, std::vector<char>, std::greater<char>>> st;
        for( std::size_t i = 0; i < s.size(); ++i )
            st[ uf.find( i ) ].push( s[ i ] );
        
        std::string res;
        for( std::size_t i = 0; i < s.size(); ++i ) {
            res += st[ uf.find( i ) ].top();
            st[ uf.find( i ) ].pop();
        }
        
        return res;
    }
};
