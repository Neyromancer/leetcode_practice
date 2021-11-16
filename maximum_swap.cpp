class Solution {
public:
    // time O( length( num ) )
    // space O( length( num ) )
    int maximumSwap(int num)
    {
        std::string digit = std::to_string( num ); // O( length( num ) )
        std::unordered_map<int,int> st;
        int index = digit.size() -1 ;
        for( int i = digit.size() - 1; i >= 0; --i ) {
            if( digit[ index ] - '0' < digit[ i ] - '0' ) // O( 1 )
                index = i;

            st[ i ] = index; // O( 1 )
        }
        
        for( int i = 0; i < digit.size(); ++i ) {
            if( digit[ i ] != digit[ st[ i ] ] ) { // O( 1 )
                std::swap( digit[ i ], digit[ st[ i ] ] ); // O( 1 )
                break;
            }
        }
        
        return std::stoi(digit); // O( sizeof( digit ) )
    }
};

class Solution {
public:
    int greater_index( const std::string& digit, const std::array<int, 10>& st, int i ) {
        int res{ 0 };
        for( int j = 0; j < st.size(); ++j ) {
            if( !st[ j ] )
                continue;

            if( digit[ st[ j ] - 1 ] - '0' > digit[ i ] - '0' && i <= st[ j ] - 1 )
                res = st[ j ] - 1;
        }
        
        return res;
    }
  
    // time O( length( num )
    // space O( 1 )  
    int maximumSwap(int num)
    {
        std::string digit = std::to_string( num );
        std::array<int, 10> st{};
        for( int i = 0; i < digit.size(); ++i )
            st[ digit[ i ] - '0' ] = i + 1;
        
        for( int i = 0; i < digit.size(); ++i ) {
            int j = greater_index( digit, st, i );
            if( i < j ) {
                std::swap( digit[ i ], digit[ j ] );
                break;
            }
        }
        
        return std::stoi( digit );
    }
};
