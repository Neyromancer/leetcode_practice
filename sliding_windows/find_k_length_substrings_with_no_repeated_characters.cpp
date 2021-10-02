class Solution {
public:
    // space O( 1 )
    // time O( sizeof( s ) )
    int numKLenSubstrNoRepeats(string s, int k)
    {
        if( s.size() < k )
            return 0;
        
        int cnt{ 0 };
        std::array<int, 27> st{};
        int l{ 0 };
        int r{ 0 };
        while( r < s.size() ) {
            ++st[ s[ r ] - 'a' ];
            // check if there is now more than 1 s[r] value
            // and remove all repeatitive values
            while( st[ s[ r ] - 'a' ] > 1 && l < r )
                --st[ s[ l++ ] - 'a' ];
 
            // check if size of the range bigger than k
            // and remove all excessive elements
            while( l < r && r - l + 1 > k )
                --st[ s[ l++ ] - 'a' ];
            
            if( r - l + 1 == k )
                ++cnt;
            
            ++r;
        }
        
        return cnt;
    }
};
