class Solution {
public:
    // time O( s.size() )
    // space O( 1 )
    int equalSubstring(string s, string t, int maxCost)
    {
        int len{ 0 };
        int wstart{ 0 };
        int cost{ 0 };
        for( int i = 0; i < s.size(); ++i ) {
            cost += std::abs( s[ i ] - t[ i ] );
            if( cost <= maxCost ) {
                len = std::max( len, i - wstart + 1 );
            } else {
                while( wstart < s.size() && cost > maxCost )
                    cost -= std::abs( s[ wstart ] - t[ wstart++ ] );
            }
        }
        
        return len;
    }
};

// space O( s.size() )
// time O( s.size() )
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        std::vector<int> st( s.size(), 0 );
        for( int i = 0; i < s.size(); ++i )
            st[ i ] = std::abs( ( s[ i ] - 'a' ) - ( t[ i ] - 'a' ) );
        
        int len{ 0 };
        int wstart{ 0 };
        int end{ 0 };
        int cost = st[ end ];
        while( end < s.size() && wstart < s.size() ) {
            if( cost <= maxCost ) {
                len = std::max( len, end - wstart + 1 );
                ++end;
                if( end < s.size() )
                    cost += st[ end ];
                    
                
            } else {
                cost -= st[ wstart++ ];
            }
        }
        
        return len;
    }
};

// time O( s.zize() )
// space O( 1 )
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int i = 0;
        int j = 0;
        for( ; i < s.size(); ++i ) {
            maxCost -= std::abs( s[ i ] - t[ i ] );
            if( maxCost < 0 )
                maxCost += std::abs( s[ j ] - t[ j++ ] );
        }
        
        return i - j;
    }
};
