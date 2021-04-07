class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K)
    {
        if( S.size() < K )
            return 0;
        
        std::array<int, 26> st{};
        st.fill( -1 );
        int cnt{ 0 };
        int start_window{ 0 };
        int i = 0;
        while( i < S.size() ) {
            if( st[ S[ i ] - 'a' ] >= 0 && start_window <= st[ S[ i ] - 'a' ] ) {
                start_window = st[ S[ i ] - 'a' ] + 1;
                st[ S[ i ] - 'a' ] = i;
            } else {
                st[ S[ i ] - 'a' ] = i;
            }
            
            if( ( i - start_window + 1 ) == K ) {
                ++cnt;
                ++start_window;
            }
            
            ++i;
        }
        
        return cnt;
    }
};
