class Solution {
public:
    // time O( sizeof( s ) )
    // space O( 1 )
    int numberOfSubstrings(string s)
    {
        std::vector<int> storage( { 0, 0, 0 } );
        int i = 0;
        int res{ 0 };
        for( int j = 0; j < s.size(); ++j ) {
            ++storage[ s[ j ] - 'a' ];
            while( storage[ 0 ] && storage[ 1 ] && storage[ 2 ] )
                --storage[ s[ i++ ] - 'a' ];
            res += i;
        }

        return res;
    }
};


