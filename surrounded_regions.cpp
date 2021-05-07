class Solution {
    std::vector<std::vector<int>> visited_indexes;
public:
    void solve(vector<vector<char>>& board)
    {
        std::vector<std::vector<int>> captured;
        init_by( visited_indexes, board );
        init_by( captured, board );
        
        for( int i = 0; i < board.size(); ++i ) {
            for( int j = 0; j < board[ i ].size(); ++j ) {
                if( board[ i ][ j ] == 'O' && visited_indexes[ i ][ j ] == 0 ) {
                    std::vector<std::vector<int>> tmp;
                    init_by( tmp, board );
                    if( is_border_met( board, tmp, i, j ) )
                        continue;
                    
                    apply_to( tmp, captured );
                }
            }
        }
        
        flip( board, captured );
    }
    
    void init_by( std::vector<std::vector<int>> &vc1,
                  const std::vector<std::vector<char>> &vc2 )
    {
        vc1.resize( vc2.size() );
        for( auto &el : vc1 )
            el.resize( vc2[ 0 ].size() );
    }
    
    bool is_border_met( const std::vector<std::vector<char>> &board,
                        std::vector<std::vector<int>> &storage,
                        int i, int j )
    {
        if( i < 0 || j < 0 || i >= board.size() || j >= board[ 0 ].size() )
            return false;

        // std::cout << "size = " << board.size() << std::endl;
        // std::cout << "i = " << i << std::endl;
        // std::cout << "j = " << j << std::endl;
        if( board[ i ][ j ] == 'O' && visited_indexes[ i ][ j ] == 1 )
            return false;
        
        if( board[ i ][ j ] == 'X' )
            return false;
        
        bool is_border = false;
        if( ( i == 0 || j == 0 || ( i == board.size() - 1 ) ||
              ( j == board[ 0 ].size() - 1 ) ) && board[ i ][ j ] == 'O' ) {
            visited_indexes[ i ][ j ] = 1;
            is_border = true;
        }
        
        visited_indexes[ i ][ j ] = 1;
        storage[ i ][ j ] = 1;
        
        auto res1 = is_border_met( board, storage, i, j + 1 );
        auto res2 = is_border_met( board, storage, i, j - 1 );
        auto res3 = is_border_met( board, storage, i + 1, j );
        auto res4 = is_border_met( board, storage, i - 1, j );
        
        return res1 || res2 || res3 || res4 || is_border;
    }
    
    void apply_to( const std::vector<std::vector<int>> &vc,
                   std::vector<std::vector<int>> &storage )
    {
        for( int i = 0; i < vc.size(); ++i ) {
            for( int j = 0; j < vc[ i ].size(); ++j ) {
                if( vc[ i ][ j ] == 1 )
                    storage[ i ][ j ] = 1;
            }
        }
    }
    
    void flip( std::vector<std::vector<char>> &board,
               const std::vector<std::vector<int>> &indexes )
    {
        for( int i = 0; i < indexes.size(); ++i ) {
            for( int j = 0; j < indexes[ i ].size(); ++j ) {
                if( indexes[ i ][ j ] == 1 )
                    board[ i ][ j ] = 'X';
            }
        }
    }
};

    // time O( N^2 x M^2 log NxM )
    // space O( N )
    void solve( vector<vector<char>>& board )
    {
        for( int i = 0; i < board.size(); ++i ) {
            for( int j = 0; j < board.front().size(); ++j ) {
                if( board[ i ][ j ] == 'O' ) {
                    std::set<std::pair<int,int>> st;
                    if( surrounded_region( board, i, j, st ) ) {
                        for( auto &[ r, c ] : st )
                            board[ r ][ c ] = 'X';
                    }
                }
            }
        }
    }
    
    bool surrounded_region( const std::vector<std::vector<char>> &board,
                            int i, int j, std::set<std::pair<int,int>> &st ) {
        if( i < 0 || j < 0 || i >= board.size() || j >= board.front().size() )
            return false;

        if( board[ i ][ j ] == 'X' )
            return true;
        
        if( st.count( { i, j } ) )
            return true;
        
        st.insert( { i, j } );
        
        return surrounded_region( board, i + 1, j, st )  &&
               surrounded_region( board, i, j - 1, st ) &&
               surrounded_region( board, i - 1, j, st ) &&
               surrounded_region( board, i, j + 1, st );
    }

class Solution {
public:
    // space O( N x M)
    // time O( N^2 x M )
    void solve(vector<vector<char>>& board) 
    {
        int r_size = board.size(); // O( 1 )
        int c_size = board.front().size(); // O( 1 )
        std::vector<std::vector<bool>> st( board.size(), std::vector<bool>( board.front().size() ) );
        for( int i = 0; i < c_size; ++i ) { // O( board.front().size() )
            if( board[ 0 ][ i ] == 'O' ) { // O( 1 )
                change( board, 0, i, '1', st );
            }
            
            if( board[ r_size - 1 ][ i ] == 'O' ) { // O( 1 )
                change( board, r_size - 1, i, '1', st );
            }
        }
        
        // O( board.size() * board.size() * board.front().size() )
        for( int i = 0; i < board.size(); ++i ) { // O( board.size() )
            if( board[ i ][ 0 ] == 'O' ) { // O( 1 )
                change( board, i, 0, '1', st ); // O( board.size() x board.front().size() )
            } 
            
            if( board[ i ][ c_size - 1 ] == 'O' ) { // O( 1 )
                change( board, i, c_size - 1, '1', st ); // O( board.size() x board.front().size() )
            }
        }
        
        // O( board.size() x board.front().size() )
        for( int i = 0; i < board.size(); ++i ) { // O( board.size() )
            for( int j = 0; j < board.front().size(); ++j ) { // O( board.front().size() )
                if( board[ i ][ j ] == 'O' ) // O( 1 )
                    board[ i ][ j ] = 'X'; // O( 1 )
            }
        }        
        
        // O( board.size() x board.front().size() )
        for( int i = 0; i < board.size(); ++i ) { // O( board.size() )
            for( int j = 0; j < board.front().size(); ++j ) { // O( board.front().size() )
                if( board[ i ][ j ] == '1' ) // O( 1 )
                    board[ i ][ j ] = 'O'; // O( 1 )
            }
        }
    }
    
    // O( board.size() x board.front().size() )
    void change( vector<vector<char>>& board, int i, int j, char ch, 
                 std::vector<std::vector<bool>> &st )
    {
        if( i < 0 || j < 0 || i >= board.size() || j >= board.front().size() )
            return;
        
        if( board[ i ][ j ] == 'X' || st[ i ][ j ] ) // O( 1 )
            return;
        
        if( board[ i ][ j ] == 'O' )
            board[ i ][ j ] = ch; // O( 1 )
        
        st[ i ][ j ] = true;
        change( board, i + 1, j, ch, st ); // O( board.size() x board.front().size() )
        change( board, i - 1, j, ch, st );
        change( board, i, j - 1, ch, st );
        change( board, i, j + 1, ch, st );
    }

class UnionFind {
    std::vector<int> id;
    std::vector<int> rank;
    int count{ 0 };

public:
    UnionFind( int N )
    {
        count = N;
        id.resize( N );
        rank.resize( N );
        std::fill( std::begin( rank ), std::end( rank ), 0 );
        for( int i = 0; i < N; ++i )
            id[ i ] = i;
    }
    
    int find_root( int p )
    {
        while( p != id[ p ] ) {
            id[ p ] = id[ id[ p ] ];
            p = id[ p ];
        }
        
        return p;
    }
    
    int get_count()
    {
        return count;
    }
    
    bool connected( int p, int q )
    {
        return find_root( p ) == find_root( q );
    }
    
    void connect( int p, int q )
    {
        int i = find_root( p );
        int j = find_root( q );
        if( i == j )
            return;
        
        if( rank[ i ] < rank[ j ] )
            id[ i ] = j;
        else if( rank[ i ] > rank[ j ] )
            id[ j ] = i;
        else {
            id[ j ] = i;
            ++rank[ i ];
        }
        
        --count;
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        int n = board.size();
        if( !n )
            return;
        
        int m = board.front().size();
        UnionFind uf( n * m + 1 );
        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < m; ++j ) {
                if( ( i == 0 || i == n - 1 || j == 0 || j == m - 1 ) && 
                  board[ i ][ j ] == 'O' ) {
                    uf.connect( i * m + j, n * m );
                } else if( board[ i ][ j ] == 'O' ) {
                    if( board[ i - 1 ][ j ] == 'O' )
                        uf.connect( i * m + j, ( i - 1 ) * m + j );
                    
                    if( board[ i + 1 ][ j ] == 'O' )
                        uf.connect( i * m + j, ( i + 1 ) * m + j );
                    
                    if( board[ i ][ j - 1 ] == 'O' )
                        uf.connect( i * m + j, i * m + j - 1 );
                    
                    if( board[ i ][ j + 1 ] == 'O' )
                        uf.connect( i * m + j, i * m + j + 1 );
                }
            }
        }
        
        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < m; ++j ) {
                if( !uf.connected( i * m + j, n * m ) )
                    board[ i ][ j ] = 'X';
            }
        }
    }
};
