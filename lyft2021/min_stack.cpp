class MinStack {
    int min_val = std::numeric_limits<int>::max();
    std::forward_list<int> st;
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    // time O( 1 )
    // space O( 1 )
    void push(int val)
    {
        min_val = std::min( min_val, val );
        st.push_front( val ); // O( 1 )
        
    }
    
    // time O( N ), where N is the size of st
    // space O( 1 )
    void pop()
    {
        if( st.empty() )
            return;

        auto val = st.front(); // O( 1 )
        st.pop_front(); // O( 1 )
        if( min_val == val ) {
            min_val = std::numeric_limits<int>::max();
            for( auto it = std::begin( st ); it != std::end( st ); ++it )
                min_val = std::min( min_val, *it );
        }
    }
  
    // time O( 1 )
    // space O( 1 ) 
    int top()
    {
        return st.front(); // O( 1 )
    }
    
    // time O( 1 ) 
    // space O( 1 )
    int getMin()
    {
        return min_val;
    }
};

// space O( N ), where N is the size of the stack
// time O( 1 )
class MinStack {
    std::forward_list<std::pair<int,int>> st;
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int val)
    {
        if( st.empty() ) {// O( 1 )
            st.emplace_front( val, val ); // O( 1 )
            return;
        }
        
        const auto &[ minv, v ] = st.front(); // O( 1 )
        st.emplace_front( std::min( minv, val ), val ); // O( 1 )
    }
    
    void pop()
    {
        if( st.empty() ) // O( 1 )
            return;

        st.pop_front(); // O( 1 )
    }
    
    int top()
    {
        if( st.empty() ) // O( 1 )
            return std::numeric_limits<int>::min();

        return st.front().second; // O( 1 )
    }
    
    int getMin()
    {
        if( st.empty() ) // O( 1 )
            return std::numeric_limits<int>::min();

        return st.front().first; // O( 1 )
    }
};

// time O( 1 )
// space O( N ) where N is the number of operation
class MinStack {
    std::forward_list<int> st;
    std::forward_list<int> min_st;
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int val)
    {
        st.push_front( val ); // O( 1 )
        if( min_st.empty() || min_st.front() >= val ) // O( 1 )
            min_st.push_front( val ); // O( 1 )
    }
    
    void pop()
    {
        if( st.empty() ) // O( 1 )
            return;
        
        auto &val = st.front(); // O( 1 )
        if( val == min_st.front() ) // O( 1 )
            min_st.pop_front(); // O( 1 )
        st.pop_front(); // O( 1 )
    }
    
    int top()
    {
        if( st.empty() ) // O( 1 )
            return std::numeric_limits<int>::min();

        return st.front(); // O( 1 )
    }
    
    int getMin()
    {
        if( st.empty() ) // O( 1 )
            return std::numeric_limits<int>::min();

        return min_st.front(); // O( 1 )
    }
};
