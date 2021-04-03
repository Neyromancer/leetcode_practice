/**
[1,2,3,4,5,6,7]
3
[1,2,3,4,5,6,7]
5
[1,2,3,4,5,6,7]
6
[1,2,3,4,5,6,7]
7
[1,2,3,4,5,6,7]
125
[1,2,3,4,5,6]
4
[1,2,3,4,5,6]
2
[-1,-100,3,99]
2
*/
// time O( N ), where N = nums.size()
// space O( 1 ) 
class Solution {
public:    
    void rotate(vector<int>& nums, int k)
    {
        if( k % nums.size() == 0 )
            return;
        
        int size = static_cast<int>( nums.size() );
        k = k % size;
        int cnt{ 0 };
        int cur{ 0 };
        int storage = nums[ cur ];
        int start{ 0 };
        while( cnt < size ) {
            do {
                cur = ( cur + k ) % size;
                std::swap( storage, nums[ cur ] );
                ++cnt;
            } while( start != cur );
            
            ++start;
            cur = start;
            storage = nums[ cur ];
        }
    }
};

/**
[1,2,3,4,5,6,7]
3
[1,2,3,4,5,6,7]
5
[1,2,3,4,5,6,7]
6
[1,2,3,4,5,6,7]
7
[1,2,3,4,5,6,7]
125
[1,2,3,4,5,6]
4
[1,2,3,4,5,6]
2
[-1,-100,3,99]
2

*/
// O( N ), where N = nums.size()
// O( 1 )
class Solution {
public:    
    void rotate(vector<int>& nums, int k)
    {
        if( k % nums.size() == 0 )
            return;
        
        int size = static_cast<int>( nums.size() );
        auto it = std::begin( nums );
        for( ; ( k = k % size ); size -= k, it += k ) {
            for( int i = 0; i < k; ++i )
                std::iter_swap( std::next( it, i ), std::next( it, size - k + i ) );
        }
    }
};
