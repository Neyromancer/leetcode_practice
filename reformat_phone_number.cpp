class Solution {
public:
    string reformatNumber(string number) 
    {
        std::string st;
        for( char ch : number ) {
            if( std::isdigit( ch ) )
                st.push_back( ch );
        }
        
        int i{ 0 };
        std::string res;
        int size = static_cast<int>( st.size() );
        while( i < size ) {
            if( size - i > 4 ) {
                res.append( st, i, 3 );
                i += 3;
            } else if( size - i == 4 ) {
                res.append( st, i, 2 );
                i += 2;
            } else if( size - i == 3 ) {
                res.append( st, i, 3 );
                i += 3;
            } else if( size - i == 2 ) {
                res.append( st, i, 2 );
                i += 2;
            }
            
            if( i < size )
                res += '-';
        }
        
        return res;
    }
};
