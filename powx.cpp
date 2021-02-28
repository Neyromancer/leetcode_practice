
// space complexity O( N ) depdens on the powers
// time complexity O( N log N )
    double myPow(double x, int n)
    {
        if( n == 0 )
            return ( x == 0 ) ? 1 : x / std::abs( x );
        
        std::vector<int64_t> powers;
        bool is_positive{ n > 0 };
        std::int64_t val = std::abs( n );
        while( val > 1 ) {
            powers.push_back( calc_power( val ) );
            val -= powers.back();
        }
        
        double res{ 1 };
        for( int p : powers ) {
            if( is_positive ) {
                res *= impowers( x, p );
            } else {
                res *= depowers( x, p );
            }
        }
        if( is_positive )
            res *= ( val ) ? x : 1;
        else
            res /= ( val ) ? x : 1;
        return res;
    }
    
    int calc_power( int n )
    {
        int res{ 1 };
        int p{ 1 };
        while( p <= n ) {
            res = p;
            if( INT_MAX / 2 < p )
                break;
            p *= 2;
        }
        return res;
    }
    
    double impowers( double x, int p )
    {
        while( p > 1 ) {
            x *= x;
            p = p / 2;
        }
        
        return x;
    }
    
    double depowers( double x, int p )
    {
        while( p > 1 ) {
            x *= x;
            p = p / 2;
        }
        
        return ( 1.0 / x );
    }
