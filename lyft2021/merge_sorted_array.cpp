class Solution {
public:
    // 1. если число из nums2 больше всех числе в nums1 то записываем его
    // в позицию m
    // 2. увеличиваем m
    // 3. если число в nums2 меньше какого то из чисел в nums2, то
    // 4. находим число превышающее текущее число и 
    // 5. начинаем записывать числа из m - 1 в позицию m
    // 6. уменьшаем m
    // time O( N x M^2 )
    // space O( 1 )
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        if( !n )
            return;

        int l{ 0 };
        for( int i = 0; i < n; ++i ) { // 0
            int v2 = nums2[ i ]; // 1
            int j = l; // 0
            for( ; j < m; ++j ) {
                if( v2 < nums1[ j ] ) {
                    rshift( nums1, j, m );
                    l = j + 1;
                    break;
                }
            }
            
            nums1[ j ] = v2;
            ++m;
            if( m >= nums1.size() )
                break;
        }
    }
    
    void rshift( std::vector<int> &vc, int l, int r )
    {
        while( l < r ) {
            vc[ r ] = vc[ r - 1 ];
            --r;
        }
    }
};
