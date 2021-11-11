class Solution {
public:
    // space O( 1 )
    // time O( sizeof( height ) * sizeof( height ) )
    int trap(vector<int>& height)
    {
        int res{ 0 };
        for( int i = 0; i < height.size(); ++i ) {
            int l{ 0 };
            for( int j = i; j >= 0; --j )
                l = std::max( l, height[ j ] );
            
            int r{ 0 };
            for( int j = i; j < height.size(); ++j )
                r = std::max( r, height[ j ] );
            
            res += std::min( l, r ) - height[ i ];
        }
        
        return res;
    }
};

ass Solution {
public:
    // space O( sizeof( height ) )
    // time O( sizeof( height ) )
    int trap(vector<int>& height)
    {
        std::unordered_map<int, int> left_height;
        int max_height = std::numeric_limits<int>::min();
        for( int i = 0; i < height.size(); ++i ) {            
            max_height = std::max( max_height, height[ i ] );
            left_height[ i ] = max_height;
        }

        std::unordered_map<int, int> right_height;
        max_height = std::numeric_limits<int>::min();
        for( int i = height.size() - 1; i >= 0; --i ) {            
            max_height = std::max( max_height, height[ i ] );
            right_height[ i ] = max_height;
        }
        
        int res{ 0 };
        for( int i = 0; i < height.size(); ++i ) {            
            res += std::min( left_height[ i ], right_height[ i ] ) - height[ i ];
        }
        
        return res;
    }
};

class Solution {
public:
    // time O( sizeof( height ) )
    // space O( sizeof( height ) )
    int trap(vector<int>& height)
    {
        std::stack<int> st;
        int res{ 0 };
        for( int i = 0; i < height.size(); ++i ) {
            while( !st.empty() && height[ st.top() ] < height[ i ] ) {
                int bottom = height[ st.top() ];
                st.pop();
                if( st.empty() )
                   continue;
                
                res += ( std::min( height[ st.top() ], height[ i ] ) - bottom ) * ( i - st.top() - 1 ); 
            }
            
            st.push( i );
        }

        return res;
    }
};

class Solution {
public:
    
    // time O( sizeof( height ) )
    // space O( 1 )
    int trap(vector<int>& height)
    {
        int res{ 0 };
        int l{ 0 };
        int r = height.size() - 1;
        int max_left{ 0 };
        int max_right{ 0 };
        while( l < r ) {
            if( height[ l ] <= height[ r ] ) {
                max_left <= height[ l ] ? 
                    max_left = height[ l ] : res += max_left - height[ l ];
                ++l;
            } else {
                max_right <= height[ r ] ? 
                    max_right = height[ r ] : res += max_right - height[ r ];
                --r;                
            }
        }
        
        return res;
    }
};
