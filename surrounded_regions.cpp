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
