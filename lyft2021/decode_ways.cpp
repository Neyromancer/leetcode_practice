/**
"1234151"
"222"
"12"
"226"
"0"
"06"
"1"
"1234151512398"
"27"
*/
class Solution {
    std::unordered_map<int,int> mem;
    // std::unordered_set<std::string> st{ "1", "2", "3", "4", "5",
    //                                     "6", "", "12", "13", "14",
    //                                     "10", "11", "12", "13", "14",
    //                                     "15", "16", "17", "18", "19",
    //                                     "20", "21", "22", "23", "24",
    //                                     "25", "26" 
    //                                   };
public:
    // time O( N ), N == s.size()
    // space O( N ), N == s.size()
    int numDecodings(string s) 
    {
        if( s.empty() )
            return 0;

        return numDecodings( s, 0 );
    }
    
    int numDecodings( std::string s, int i )
    {
        if( mem.count( i ) )
            return mem[ i ];

        if( i == s.size() )
            return 1;

        if( i >= s.size() )
            return 0;

        if( s[ i ] == '0' )
            return 0;
        
        int ans = numDecodings( s, i + 1 );
        if( stoi( s.substr( i, 2 ) ) <= 26 )
            ans += numDecodings( s, i + 2 );
        
        
        mem[ i ] = ans;
        return ans;
    }
};
