class Solution {
    std::unordered_map<int, int> st;
public:
    // time O( N ), where N is the size of the longest word
    // space O( 1 )
    bool are_sorted( std::string_view w1, std::string_view w2 )
    {
        for( int i = 0; i < w1.size(); ++i ) {
            if( i >= w2.size() || st[ w1[ i ] - 'a' ] > st[ w2[ i ] - 'a' ] )
                return false;
            else if( st[ w1[ i ] - 'a' ] < st[ w2[ i ] - 'a' ] )
                return true;
        }
        
        return true;
    }
   
    // time O( N * M ), where N is the size of the words, and M is the size of the longest word
    // space O( 1 ) 
    bool isAlienSorted(vector<string>& words, string order)
    {
        for( int i = 0; i < order.size(); ++i )
            st[ order[ i ] - 'a' ] = i;
        
        for( int i = 1; i < words.size(); ++i ) {
            if( !are_sorted( words[ i - 1 ], words[ i ] ) )
                return false;
        }
        
        return true;
    }
};
