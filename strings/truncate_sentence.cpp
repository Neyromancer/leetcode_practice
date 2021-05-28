class Solution {
public:
    // time O( k * N ), where N == s.size()
    // space O( 1 )
    string truncateSentence(string s, int k)
    {
        int i = 0;
        while( k-- > 0 ) {
            i = s.find( " ", i );
            if( i == std::string::npos )
                break;
            
            ++i;
        }

        if( k <= 0)
            --i;

        return s.substr( 0, i );        
    }
};
