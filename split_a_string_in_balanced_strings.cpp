// time O( N^2 ), N = s.size()
// space O( 1 )
class Solution {
public:
    int balancedStringSplit(string s)
    {
        int cnt{ 0 };
        int j{ 0 };
        for( int i = 0; i < s.size(); ++i ) {
            if( ( i - j + 1 ) % 2 == 0 ) {
                if( is_balanced( s, j, i ) ) {
                    j = i + 1;
                    ++cnt;
                }
            }
        }
        
        return cnt;
    }
    
    bool is_balanced( const std::string &s, int start, int end )
    {
        int l{ 0 };
        int r{ 0 };
        for( int i = start; i <= end; ++i ) {
            if( s[ i ] == 'L' )
                ++l;
            else
                ++r;
        }
        
        return r == l;
    }
};

// time O( N ), where N = s.size()
// space O( 1 )
class Solution {
public:
    int balancedStringSplit(string s)
    {
        int cnt{ 0 };
        int j{ 0 };
        std::array<int,2> storage{};
        for( int i = 0; i < s.size(); ++i ) {
            if( s[ i ] == 'R' )
                ++storage[0];
            else
                ++storage[1];
            
            if( ( i - j + 1 ) % 2 == 0 ) {
                if( storage[ 1 ] == storage[ 0 ] ) {
                    j = i + 1;
                    storage[0] = 0;
                    storage[1] = 0;
                    ++cnt;
                }
            }
        }
        
        return cnt;
    }
};
