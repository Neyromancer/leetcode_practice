class MaxStack {
    std::forward_list<int> st;
    std::forward_list<int> max_st;
public:
    /** initialize your data structure here. */
    MaxStack() {}
    
    void push( int x )
    {
        int m = max_st.empty() ? x : max_st.front();
        max_st.push_front( m > x ? m : x ); // O( 1 )
        st.push_front( x ); // O( 1 )
    }
    
    // time O( 1 )
    int pop()
    {
        if( st.empty() )
            return -1;

        int v = st.front(); // O( 1 )
        st.pop_front(); // O( 1 )
        max_st.pop_front(); // O( 1 )
        return v;
    }
    
    // time O( 1 )
    int top()
    {
        if( st.empty() )
            return -1;

        return st.front(); // O( 1 )
    }
    
    // O( 1 )
    int peekMax()
    {
        if( max_st.empty() )
            return -1;

        return max_st.front(); // O( 1 )
    }
    
    // time O( N ), where N == st.size()
    // space O( N ), where N == st.size()
    int popMax()
    {
        if( max_st.empty() )
            return -1;

        int v = peekMax();  //
        std::forward_list<int> tmp;
        while( !st.empty() && v != top() )
            tmp.push_front( pop() );
        
        pop();
        while( !tmp.empty() ) {
            push( tmp.front() );
            tmp.pop_front();
        }
        
        return v;
    }
};

/**
["MaxStack","push","push","push","top","popMax","top","peekMax","pop","top"]
[[],[5],[1],[5],[],[],[],[],[],[]]
["MaxStack","push","push","push","pop","peekMax","top"]
[[],[5],[1],[5],[],[],[]]
["MaxStack","push","push","popMax","peekMax"]
[[],[5],[1],[],[]]
["MaxStack","push","push","popMax","popMax"]
[[],[5],[5],[],[]]
*/
class MaxStack {
    std::list<int> st;
    std::map<int, std::list<decltype( std::begin( st ) )>, std::greater<int>> mp;
public:
    /** initialize your data structure here. */
    MaxStack() {}
    
    void push(int x)
    {
        st.push_front( x ); // O( 1 )
        if( !mp.count( x ) ) // O( 1 )
            mp.insert( { x, { std::begin( st ) } } ); // O( 1 )
        else
            mp[ x ].push_front( std::begin( st ) ); // O( 1 ) * O( log sizeof mp )
    }
    
    int pop()
    {
        int val = st.front(); // O( 1 )
        st.pop_front(); // O( 1 )
        auto &connections = mp.at( val ); // O( log sizeof mp )
        connections.pop_front(); // O( 1 )
        if( connections.empty() ) // O( 1 )
            mp.erase( val ); // O( 1 )
        
        return val;
    }
    
    int top()
    {
        return st.front(); // O( 1 )
    }
    
    int peekMax()
    {
        const auto &[ val, con ] = *std::begin( mp ); // O( 1 )
        return val;
    }
    
    int popMax()
    {
        int mval = peekMax(); // O( 1 )
        auto &connections = mp.at( mval ); // O( log sizeof mp )
        auto node = connections.front(); // O( 1 )
        st.erase( node ); // O( 1 )
        connections.pop_front(); // O( 1 )
        if( connections.empty() ) // O( 1 )
            mp.erase( mval ); // O( 1 )
        
        return mval;
    }
};
