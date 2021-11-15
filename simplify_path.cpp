/*
"/.././_/"
"/home/"
"/../"
"/home//foo/"
"/a/./b/../../c/"
"/_"
"/../../../."
 "/../.."
 "/."
 "/.."
 "///"
 "/"
 "//"
 "/a"
 "/a/a"
 "/./a"
 "/a"
 "/a/a/../a/_"
  "/..."
 "/...."
*/

class Solution {
public:
    // time O( sizeof( path ) )
    // space O( sizeof( path ) )
    string simplifyPath(string path) {
        int r{ 0 };
        std::stack<std::string> st;
        // O( sizeof( path ) )
        while( r < path.size() ) {
            if( path[ r ] != '/' ) { // O( 1 )
                std::string tmp;
                while( r < path.size() && path[ r ] != '/' ) // O( 1 )
                    tmp += path[ r++ ]; // O( 1 )

                if( tmp.size() == 2 && tmp[ 0 ] == tmp[ 1 ] && tmp[ 1 ] == '.' ) { // O( 1 )
                    if( st.empty() ) // O( 1 )
                        continue;
                    
                    if( st.top() == "/" ) // O( 1 )
                        st.pop();
                    
                    st.pop(); // O( 1 )
                    
                    if( st.top() == "/" ) // O( 1 )
                        st.pop(); // O( 1 )
                    continue;
                } else if( tmp.size() == 1 && tmp[ 0 ] == '.' ) // O( 1 )
                    continue;
                
                st.push( "/" ); // O( 1 )
                st.push( tmp ); // O( 1 )

                continue;
            }
            
            ++r;
        }
        
        if( st.empty() ) // O( 1 )
            return "/";
        
        std::vector<std::string> tmp;
        // O( sizeof( path ) )
        while( !st.empty() ) {
            tmp.push_back( st.top() ); // O( 1 )
            st.pop(); // O( 1 )
        }
        
        // O( sizeof( tmp ) )
        std::reverse( std::begin( tmp ), std::end( tmp ) );
        std::string res;
        for(auto &&el : tmp)
            res += el;
        return res;
    }
};

/*
"/.././_/"
"/home/"
"/../"
"/home//foo/"
"/a/./b/../../c/"
"/_"
"/../../../."
 "/../.."
 "/."
 "/.."
 "///"
 "/"
 "//"
 "/a"
 "/a/a"
 "/./a"
 "/a"
 "/a/a/../a/_"
  "/..."
 "/...."
*/

class Solution {
public:
    // time O( sizeof( path ) )
    // space O( sizeof( path ) )
    string simplifyPath(string path) {
        int r{ 0 };
        std::stack<std::string> st;
        // O( sizeof( path ) )
        while( r < path.size() ) {
            if( path[ r ] != '/' ) { // O( 1 )
                std::string tmp;
                while( r < path.size() && path[ r ] != '/' ) // O( 1 )
                    tmp += path[ r++ ]; // O( 1 )

                if( tmp.size() == 2 && tmp[ 0 ] == tmp[ 1 ] && tmp[ 1 ] == '.' ) { // O( 1 )
                    if( st.empty() ) // O( 1 )
                        continue;
   
                    st.pop(); // O( 1 )
                    continue;
                } else if( tmp.size() == 1 && tmp[ 0 ] == '.' ) // O( 1 )
                    continue;

                st.push( tmp ); // O( 1 )
                continue;
            }
            
            ++r;
        }
        
        if( st.empty() ) // O( 1 )
            return "/";
        
        std::vector<std::string> tmp;
        // O( sizeof( path ) )
        while( !st.empty() ) {
            tmp.push_back( st.top() ); // O( 1 )
            st.pop(); // O( 1 )
        }
        
        // O( sizeof( tmp ) )
        std::reverse( std::begin( tmp ), std::end( tmp ) );
        std::string res;
        for(auto &&el : tmp) {
            res += "/";
            res += el;
        }
        return res;
    }
};
