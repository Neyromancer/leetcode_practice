// time O( s.size() x len( k ) )
// space O( k )
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        if( s.size() <= k )
            return s.size();
        
        int l{ 0 };
        int len{ 0 };
        std::unordered_map<int, int> st;
        for( int r = 0; r < s.size(); ++r ) {
            st[ s[ r ] - 'A' ] = r;
            if( st.size() > k ) {
                int i{ INT_MAX };
                for( const auto &[el, index] : st )
                    i = std::min( index, i );
                
                st.erase( s[ i ] - 'A' );
                l = i + 1;
            }
            
            len = std::max( len, r - l + 1 );
        }
        
        return len;
    }
};
// time O( N )
// space O( k )
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        if( s.empty() || !k )
            return 0;
        std::unordered_map<char, int> st;
        int l{ 0 };
        int len{ 0 };
        int r = 0;
        for( ; r < s.size(); ++r ) {
            len = std::max( len, r - l );
            if( !st.count( s[ r ] ) ) {
                if( st.size() == k ) {
                    while( --st[ s[ l ] ] != 0 )
                        ++l;
                    
                    st.erase( s[ l++ ] );
                }
            }
            ++st[ s[ r ] ];
        }
        len = std::max( len, r - l );

        return len;
    }
};

class OrderedDict {
    std::unordered_map<char,std::list<std::pair<char,int>>::iterator> st;
    std::list<std::pair<char,int>> lst;
public:
    // time O( 1 )
    void insert( char ch, int index )
    {
        lst.emplace_back( ch, index ); // O( 1 )
        st[ ch ] = std::prev( std::end( lst ) ); // O( 1 )
    }
    
    // time O( 1 )
    void erase( char ch )
    {
        if( !st.count( ch ) ) // O( 1 )
            return;
        
        lst.erase( st[ ch ] ); // O( 1 )
        st.erase( ch ); // O( 1 )
    }
    
    // time O( 1 )
    std::pair<char,int> at( char ch )
    {
        if( !st.count( ch ) ) // O( 1 )
            return {};
        return *st[ ch ]; // O( 1 )
    }
    
    // time O( 1 )
    std::pair<char,int> leftmost()
    {
        return lst.front(); // O( 1 )
    }
    
    // time O( 1 )
    bool is_contain( char ch )
    {
        return st.count( ch ) == 1; // O( 1 )
    }
    
    // time O( 1 )
    std::size_t size()
    {
        return st.size(); // O( 1 )
    }
};

/**
"eceba"
2
"aa"
1
"aa"
2
"accaaaaaaec"
1
"accaaaaaaec"
0
"accaaaaaaec"
3
"abcde"
2
"abaccc"
2
*/

class Solution {
public:
    // time O( sizeof( s ) )
    // space O( sizeof( s ) )
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        if( s.size() * k == 0 )
            return 0;
        
        OrderedDict dict;
        int l{ 0 };
        int len{ 0 };
        int r{ 0 };
        int sz = static_cast<int>( s.size() );
	// time O( sizeof( s ) )
        while( r < sz ) {
            // time O( 1 )
            if( dict.is_contain( s[ r ] ) )
                dict.erase( s[ r ] ); // O( 1 )
            
            dict.insert( s[ r ], r++ ); // O( 1 )
            if( static_cast<int>( dict.size() ) == k + 1 ) { // O( 1 )
                auto val = dict.leftmost(); // O( 1 )
                l = val.second + 1;
                dict.erase( val.first ); // O( 1 )
            }

            len = std::max( len, r - l );
        }
        
        return len;
    }
};
