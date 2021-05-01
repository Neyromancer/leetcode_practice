// DFS
class Solution {
    std::vector<std::vector<int>> storage;
public:
    int numIslands(const vector<vector<char>>& grid)
    {
        storage.resize( grid.size() );
        for( auto &vc : storage )
            vc.resize( grid.front().size() );

        int cnt{ 0 };
        for( int i = 0; i < grid.size(); ++i ) {
          for( int j = 0; j < grid[ i ].size(); ++j ) {
           if( grid[ i ][ j ] == '1' && storage[ i ][ j ] != 1 ) {
             walk( grid, i, j );
             ++cnt;
           }
          }
       }

       return cnt;
    }

    void walk( const std::vector<std::vector<char>> &space, int i, int j )
    {
      if( i < 0 || j < 0 || i >= space.size() || j >= space[ 0 ].size() )
        return;

      if( space[ i ][ j ] == '1' && storage[ i ][ j ] == 1 )
        return;

      if( space[ i ][ j ] == '0' )
        return;

      if( space[ i ][ j ] == '1' && storage[ i ][ j ] == 0 )
        storage[ i ][ j ] = 1;

      walk( space, i + 1 , j );
      walk( space, i - 1 , j );
      walk( space, i, j + 1 );
      walk( space, i, j - 1 );
   }
};


// UnionFind
class Solution {
    /*
[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]
[["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]    
    */
    class UnionFind {
        int count{ 0 };
        std::vector<int> parents;
    public:
        UnionFind( const std::vector<std::vector<char>> &grid )
        {
            int rows = grid.size();
            int cols = grid.front().size();
            parents.resize( cols * rows );
            for( int i = 0; i < rows; ++i ) {
                for( int j = 0; j < cols; ++j ) {
                    if( grid[ i ][ j ] == '1' ) {
                        ++count;
                        int id = i * cols + j;
                        parents[ id ] = id;
                    }
                }
            }
        }
        
        int find_root( int p )
        {
            while( p != parents[ p ] )
                p = parents[ p ];
            
            return p;
        }
        
        void merge( int p, int q )
        {
            int pi = find_root( p );
            int qi = find_root( q );
            if( pi == qi )
                return;
            
            parents[ pi ] = qi;
            --count;
        }
        
        int islands()
        {
            return count;
        }
    };
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int rows = grid.size();
        int cols = grid.front().size();
        std::vector<std::vector<int>> neighbors{ { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        UnionFind uf{ grid };
        for( int i = 0; i < rows; ++i ) {
            for( int j = 0; j < cols; ++j ) {
                if( grid[ i ][ j ] == '1' ) {
                    for( auto &n : neighbors ) {
                        int y = i + n[ 0 ];
                        int x = j + n[ 1 ];
                        if( x >= 0 && y < rows && y >= 0 && x < cols && grid[ y ][ x ] == '1' ) {
                            int id1 = i * cols + j;
                            int id2 = y * cols + x;
                            uf.merge( id1, id2 );
                        }
                    }
                }
            }
        }
        
        return uf.islands();
    }
};
