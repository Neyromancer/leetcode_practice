class Solution {
public:
    int mySqrt(int x)
    {
        if( x <= 1 )
            return x;

        int res{ 0 };
        for( std::size_t i = 1; i < x; ++i ) {
            if( i > ( x / i ) )
                break;

            res = i;
        }
        
        return res;
    }
};
