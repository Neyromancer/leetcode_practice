class Solution {
public:
    // time O( N )
    // space O( N )
    string removeDuplicates(string s)
    {
        std::stack<int> st;
        std::unordered_set<int> indexes;
        for( int i = 0; i < s.size(); ++i ) {
            if( st.empty() || s[ st.top() ] != s[ i ] ) { // O( 1 )
                st.push( i ); // O( 1 )
                continue;
            }
            
            indexes.insert( st.top() ); // O( 1 )
            indexes.insert( i ); // O( 1 )
            st.pop(); // O( 1 )
        }
        
        std::string res;
        for( int i = 0; i < s.size(); ++i ) {
            if( indexes.count( i ) ) // O( 1 )
                continue;
            
            res += s[ i ];
        }
        
        return res;
    }
};

class Solution {
public:
    // time O( N )
    // space O( N )
    string removeDuplicates(string s)
    {
        std::stack<int> st;
        for( int i = 0; i < s.size(); ++i ) {
            if( st.empty() || s[ st.top() ] != s[ i ] ) { // O( 1 )
                st.push( i ); // O( 1 )
                continue;
            }

            st.pop(); // O( 1 )
        }
        
        std::string res;
        while( !st.empty() ) {
            int i = st.top();
            res += s[ i ];
            st.pop();
        }
        
        std::reverse( std::begin( res ), std::end( res ) ); // O( N )
        return res;
    }
};
