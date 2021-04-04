class Solution {
public:
    // "c abc ad"
    /**
      a 1
      b 1      
      c 1
    
    
    */
    // time O( s.size() )
    // space O( 1 )
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        std::array<int, 128> st{};
        int l{ 0 }; // 1
        int cnt_letters{ 0 };
        int length{ 0 }; // 2
        for( int r = 0; r < s.size(); ++r ) { // 3
            if( st[ s[ r ] - 'A' ] ) {  
                ++st[ s[ r ] - 'A' ];
            } else {
                if( cnt_letters < 2 ) { // 1
                    ++st[ s[ r ] - 'A' ];
                    ++cnt_letters; // 1
                } else {
                    while( l < s.size() && cnt_letters >= 2 ) {
                        --st[ s[ l ] - 'A' ];
                        if( st[ s[ l ] - 'A' ] == 0 )
                            --cnt_letters;
                        
                        ++l;
                    }
                    ++st[ s[ r ] - 'A' ];
                    ++cnt_letters;
                }
            }
            
            length = std::max( length, r - l + 1 ); // 2, 2 - 1 + 1 = 2 -> 2
        }
        
        return length;
    }
};

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        if( s.size() < 3 )
            return s.size();
        
        int l{ 0 };
        int len{ 2 };
        std::unordered_map<int, int> st;
        for( int r = 0; r < s.size(); ++r ) {
            st[ s[ r ] - 'A' ] = r;
            if( st.size() > 2 ) {
                int i{ INT_MAX };
                for( auto &[ el, index ] : st )
                    i = std::min( i, index );

                st.erase( s[ i ] - 'A' );
                l = i + 1;
            }

            len = std::max( len, r - l + 1 );
        }
        
        return len;
    }
};
