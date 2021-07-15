class Solution {
public:
    // time O( N ), N == seats.size
    // space O( 1 )
    int maxDistToClosest(vector<int>& seats)
    {
        int j{ 0 };
        int len{ 1 };
        int i{ 0 };
        for( ; i < seats.size(); ++i ) {
            if( seats[ i ] ) {
                len = std::max( len, ( seats[ j ] ? ( i - j ) / 2 :
                                      ( i - j ) ) );
                j = i;
            }
        }
        
        len = std::max( len, ( i - 1 ) - j );
        return len;
    }
};
