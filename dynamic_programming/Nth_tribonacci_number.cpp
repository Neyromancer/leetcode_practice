// Top-up implementation
class Solution {
    std::unordered_map<int, int> storage;
public:
    // TC: O( n )
    // SC: O( n )
    int tribonacci(int n) {
        if( n == 0 )
            return 0;
        
        if( n == 1 )
            return 1;
        
        if( n == 2 )
            return 1;
        
        if( storage.count( n ) )
            return storage[ n ];
        
        storage[ n ] = tribonacci( n - 1 ) + tribonacci( n - 2 ) + tribonacci( n - 3 );
        return storage[ n ];
    }
};

// Bottom-up implementaiton
class Solution {
public:
    // TC: O( n )
    // SC: O( 1 )
    int tribonacci(int n)
    {
        if( !n )
            return 0;
        
        if( n <= 2 )
            return 1;
        
        int first = 0;
        int second = 1;
        int third = 1;
        for( int i = 3; i <= n; ++i ) {
            int tmp = first + second + third;
            first = second;
            second = third;
            third = tmp;
        }
        
        return third;
    }
};
