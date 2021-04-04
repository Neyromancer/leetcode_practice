// time O( s.size() x len( k ) )
// space O( k )
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        if( s.size() <= k )
            return s.size();
        
        int l{ 0 };
        int len{ 0 };
        std::unordered_map<int, int> st;
        for( int r = 0; r < s.size(); ++r ) {
            st[ s[ r ] - 'A' ] = r;
            if( st.size() > k ) {
                int i{ INT_MAX };
                for( const auto &[el, index] : st )
                    i = std::min( index, i );
                
                st.erase( s[ i ] - 'A' );
                l = i + 1;
            }
            
            len = std::max( len, r - l + 1 );
        }
        
        return len;
    }
};
