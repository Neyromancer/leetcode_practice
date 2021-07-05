class Solution {
    std::unordered_map<char, char> opposite {
        { '{', '}' }, { '(', ')' }, { '[', ']' }
    };
public:
    // time O( N ), where N == s.size()
    // space O( N ), where N == s.size()
    bool isValid(string s)
    {
        std::stack<char> st;
        for( std::size_t i = 0; i < s.size(); ++i ) {
            if( st.empty() && is_closing( s[ i ] ) )// O( 1 )
                return false;
            
            if( !is_closing( s[ i ] ) ) { // O( 1 )
                st.push( s[ i ] );
                continue;
            }
            
            if( !are_opposite( st.top(), s[ i ] ) ) // O( 1 )
                return false;
            else
                st.pop(); // O( 1 )
        }
        
        return st.empty();
    }
    
    bool is_closing( char ch )
    {
        return ch == ']' || ch == '}' || ch == ')';
    }
    
    bool are_opposite( char ch1, char ch2 )
    {
        return opposite[ ch1 ] == ch2; // O( 1 )
    }
};
