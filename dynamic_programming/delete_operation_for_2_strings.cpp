class Solution {
public:
    // space O( N ), where N == std::min( word1.size(), word2.size() )
    // time O( 2^N ), where N == std::min( word1.size(), word2.size() )
    int minDistance(string word1, string word2)
    {
        return countMinDistance( word1, word2, 0, 0 );
    }
    
    int countMinDistance( std::string_view w1, std::string_view w2, int i, int j )
    {
        if( i >= w1.size() )
            return w2.size() - j;
        
        if( j >= w2.size() )
            return w1.size() - i;
        
        if( w1[ i ] == w2[ j ] )
            return countMinDistance( w1, w2, i + 1, j + 1 );
        
        return 1 + std::min( countMinDistance( w1, w2, i + 1, j ),
                             countMinDistance( w1, w2, i, j + 1 ) );
    }
};

class Solution {
public:
    // space O( N^2 ), where N == std::min( word1.size(), word2.size() )
    // time O( 2^N ), where N == std::min( word1.size(), word2.size() )
    int minDistance(string word1, string word2)
    {
        std::vector<std::vector<int>> dp( word1.size(), std::vector<int>( word2.size() ) );
        return countMinDistance( word1, word2, dp, 0, 0 );
    }
    
    int countMinDistance( std::string_view w1, std::string_view w2, 
                          std::vector<std::vector<int>> &dp, int i, int j )
    {
        if( i >= w1.size() )
            return w2.size() - j;
        
        if( j >= w2.size() )
            return w1.size() - i;
        
        if( !dp[ i ][ j ] ) {
            if( w1[ i ] == w2[ j ] )
                dp[ i ][ j ] = countMinDistance( w1, w2, dp, i + 1, j + 1 );
            else
                dp[ i ][ j ] = 1 + std::min( countMinDistance( w1, w2, dp, i, j + 1 ),
                                             countMinDistance( w1, w2, dp, i + 1, j ) );
        }
        
        return dp[ i ][ j ];
    }
};


