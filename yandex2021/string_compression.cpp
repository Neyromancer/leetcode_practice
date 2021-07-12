class Solution {
public:
    /***
    ["a","a","b","b","c","c","c"]
["a"]
["a","b","b","b","b","b","b","b","b","b","b","b","b"]
["a","a","a","b","b","a","a"]
["a","b","c"]
["a","a","a","a","a","a","b","b","b","b","b","b","b","b","b","b","b","b","b","b","b","b","b","b","b","b","b","c","c","c","c","c","c","c","c","c","c","c","c","c","c"]
    */
    // time O( N ), N == chars.size
    // space O( 1 )
    int compress(vector<char>& chars)
    {
        if( chars.empty() )
            return 0;
        
        int i{ 0 };
        int r{ 0 };
        while( i < chars.size() ) {
            int cnt{ 1 };
            char var = chars[ i ];
            int j = i + 1;
            while( j < chars.size() && var == chars[ j ] ) {
                ++cnt;
                ++j;
            }
            
            chars[ r ] = chars[ i ];
            ++r;
            if( cnt > 1 ) {
                if( cnt < 10 ) {
                    chars[ r++ ] = static_cast<char>( '0' + cnt );
                } else {
                    int power = count_power( cnt );                    
                    while( power >= 0 ) {
                        chars[ r++ ] = static_cast<char>( '0' + cnt / static_cast<int>( std::pow( 10, power ) ) );
                        cnt %= static_cast<int>( std::pow( 10, power ) );
                        --power;
                    }
                }
            }
            
            i = j;
        }
        
        return r;
    }
    
    int count_power( int num )
    {
        int cnt{ 0 };
        while( num = num / 10 ) ++cnt;
        return cnt;
    }
};
