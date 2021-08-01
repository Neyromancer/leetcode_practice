class Solution {
public:
    // time O( sizeof( tokens )
    // space O( sizeof( tokens )
    int evalRPN(vector<string>& tokens)
    {
        std::stack<int> st;
        // time O( sizeof( topkens ) )
        for( int i = 0; i < tokens.size(); ++i ) {
            if( !is_digit( tokens[ i ] ) ) {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                
                st.push( evaluate( n2, n1, tokens[ i ][ 0 ] ) );
                continue;
            }
            
            st.push( std::stoi( tokens[ i ] ) );
        }
        
        return st.top();
    }
    
    int evaluate( int n1, int n2, char op )
    {
        if( op == '+' )
            return n1 + n2;
        else if( op == '-' )
            return n1 - n2;
        else if( op == '/' )
            return n1 / n2;
        return n1 * n2;
    }
    
    bool is_digit( const std::string &num )
    {
        try {
            std::stoi( num );
        } catch( ... ) {
            return false;
        }
        
        return true;
    }
};
