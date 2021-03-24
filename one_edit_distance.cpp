// space O( N ), where N - length of the longest string
// time O( N ), where N - length of the longest string

/**
"ab"
"acb"
"A"
"a"
"abc"
"aBc"
"abc"
"acb"
""
""
"A"
"a"
"a"
""
""
"A"
"abcde"
"bacde"
"teacher"
"detacher"
"abcc"
"acc"
*/
class Solution {
public:
    bool isOneEditDistance(string s, string t)
    {
        int s_size = s.size();
        int t_size = t.size();
        if( std::abs( s_size - t_size ) > 1 )
            return false;
        
        if( s_size == t_size ) {
            int cnt = 0;
            for( int i = 0; i < s.size(); ++i )
                if( s[ i ] != t[ i ] )
                    ++cnt;
            
            return cnt == 1;
        } else {
           std::string longest = t_size > s_size ? t : s;
           std::string smallest = t_size > s_size ? s : t;
           int i = 0;
           int j = 0;
            while( i < longest.size() && j < smallest.size() ) {
               if( longest[ i ] != smallest[ j ] ) {
                   ++i;
                   while( i < longest.size() && j < smallest.size() &&
                          longest[ i ] == smallest[ j ] ) {
                       ++i;
                       ++j;
                   }
                   
                   if( i >= longest.size() || j >= smallest.size() )
                       return true;
                   
                   return false;
               }
               
               ++i;
               ++j;
           }
        }
        
        return true;
    }
};
