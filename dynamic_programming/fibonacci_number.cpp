// Top-down implementation
class Solution {
    std::unordered_map<int, int> storage;
public:
    // TC: O( n )
    // SC: O( n )
    int fib(int n) {
        if( n == 0 )
            return 0;
        
        if( n == 1 )
            return 1;
        
        if( storage.count( n ) )
            return storage[ n ];
        
        storage[ n ] = fib( n - 1 ) + fib( n - 2 );
        return storage[ n ];
    }
};

// Bottom-Up implementaion
class Solution {
public:
    // TC: O( n )
    // SC: O( 1 )
    int fib(int n)
    {
        if( n <= 1 )
            return n;

        int first = 0;
        int second = 1;
        for( int i = 2; i <= n; ++i ) {
            int tmp = first + second;
            first = second;
            second = tmp;
        }
        
        return second;
    }
};

