class Solution {
public:
    /*
    2.00000
10
2.10000
3
2.00000
-2
0.001
1000
1.00000
2147483647
-1.00000
2147483647
2.00000
-2147483648
1.00000
-2147483647
-1.00000
-2147483647
    
    */
    double myPow(double x, int n) {
        if( !n )
            return 1;
        
        if( !x )
            return x;
        
        if( std::abs( x ) == 1 ) {
            if( x < 0 )
                return n > 0 ? ( ( n % 2 == 0 ) ? std::abs( x ) : x ) : 
            1 / ( ( ( n % 2 == 0 ) ? std::abs( x ) : x ) );
            return n > 0 ? x : 1 / x;
        }
        
        std::int64_t N = n;
        if( N < 0 ) {
            x = 1 / x;
            N = -N;
        }
            
        double res{ 1.0 };
        for( std::int64_t i = 0; i < N; ++i )
            res *= x;
        
        return res; 
    }
};

class Solution {
public:
    
    // space O( log n )
    // time O( log( n ) )
    double myPow(double x, int n)
    {
        int64_t N = n;
        if( N < 0 ) {
            N = -N;
            x = 1 / x;
        }
        
        if( N == 1 )
            return x;
        
        if( N == 0 )
            return 1;
        
        auto res = myPow( x, ( N % 2 == 0 ? N / 2 : ( N - 1 ) / 2 ) );
        return res * res * ( ( N % 2 == 0 ) ? 1 : x );
    }
};
