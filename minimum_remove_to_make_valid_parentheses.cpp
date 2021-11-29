class Solution {
public:
    // space O( sizeof( s ) )
    // time O( sizeof( s ) )
    string minRemoveToMakeValid(string s)
    {
        std::stack<std::pair<char, int>> st;
        for( int i = 0; i < s.size(); ++i ) {
            if( !st.empty() && s[ i ] == ')' && std::get<0>( st.top() ) == '(' ) {
                st.pop();
                continue;
            }

            if( !std::isalpha( s[ i ] ) )
                st.push( std::make_pair( s[ i ], i ) );
        }
        
        while( !st.empty() ) {
            s[ std::get<1>( st.top() ) ] = 'A';
            st.pop();
        }
        
        std::string res;
        for( int i = 0; i < s.size(); ++i ) {
            if( s[ i ] != 'A' )
                res += s[ i ];
        }
        
        return res;
    }
};
