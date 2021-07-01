class Solution {
public:
    // time O( N log N ), where N is the size of arr
    // space O( N ), where N is the size of the arr
    int minSetSize( vector<int>& arr )
    {
        std::unordered_map<int, int> digit_counter;
        for( int n : arr )
            ++digit_counter[ n ]; // O( 1 )

        std::multiset<int, std::greater<int>> st;
        for( const auto &[ d, cnt ] : digit_counter )
            st.insert( cnt ); // O( log N )
        
        int cnt{ 0 };
        int sz{ 0 };
        for( auto l : st ) {
            if( sz >= arr.size() / 2 )
                return cnt;
            
            ++cnt;
            sz += l;
        }
        
        return cnt;
    }
};

class Solution {
public:
    // time O( N log N ), where N is the size of arr
    // space O( N ), where N is the size of the arr
    int minSetSize( vector<int>& arr )
    {
        std::vector<int> st(100001);
        for( int n : arr )
            ++st[ n ]; // O( 1 )

        // O( N log N )
        std::sort( std::begin( st ), 
                  std::end( st ), std::greater<int>() );
        
        int cnt{ 0 };
        int sz{ 0 };
        for( int i = 0; i < st.size(); ++i ) {
            if( sz >= arr.size() / 2 )
                return cnt;
            
            ++cnt;
            sz += st[ i ];
        }
        
        return cnt;
    }
};


class Solution {
public:
    // O( N log N ), where N == arra.size()
    // O( N ), where N == arra.size() 
    int minSetSize(vector<int>& arr)
    {
        std::vector<int> st( 100001 );
        // O( N ), where N == arr.size()
        for( int d : arr )
            ++st[ d ]; // O( 1 )
        
        std::priority_queue<int> q;
        for( int i = 0; i < st.size(); ++i ) {
            if( st[ i ] )
                q.push( st[ i ] ); // O( log M ), where M is the size of q
        }
        
        int cnt{ 0 };
        int l{ 0 };
        int m = arr.size() / 2;
        while( !q.empty() ) {
            if( l >= m )
                return cnt;
            
            ++cnt;
            l += q.top(); // O( 1 )
            q.pop(); // O( log M ), where M == q.size
        }
        
        return cnt;
    }
};
