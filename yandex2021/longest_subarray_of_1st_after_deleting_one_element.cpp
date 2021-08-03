class Solution {
public:
    // O( N ), N == nums.size()
    // O( 1 )
    int longestSubarray( vector<int>& nums )
    {
        int l{ 0 };
        int len{ 0 };
        int index{ 0 };
        bool is_zero{ false };
        int r = 0;
        for( ; r < nums.size(); ++r ) {
            if( !nums[ r ] ) {
                if( is_zero ) {
                    len = std::max( len, r - l - 1 );
                    l = index + 1;
                    index = r;
                } else {
                    is_zero = true;
                    index = r;
                }
            }
        }
        
        l = l + 1;
        len = std::max( len, r - l );
        
        return len;
    }
};

class Solution {
public:
    // time O( N ), N == nums.size
    // space O( 1 )
    int longestSubarray( vector<int>& nums )
    {
        int prev_cnt{ 0 };
        int cnt{ 0 };
        int res{ 0 };
        for( int i = 0; i < nums.size(); ++i ) {
            if( nums[ i ] ) {
                ++cnt;
            } else {
                res = std::max( res, prev_cnt + cnt );
                prev_cnt = cnt;
                cnt = 0;
            }
        }
        
        return ( cnt == nums.size() ? cnt - 1 : std::max( res, prev_cnt + cnt ) );
    }
};

class Solution {
public:
    // time O( N ), N == nums.size
    // space O( 1 )
    int longestSubarray(vector<int>& nums)
    {
        int cnt{ nums[ 0 ] };
        int prev{ 0 };
        int res{ 0 };
        for( int i = 1; i < nums.size(); ++i ) {
            if( nums[ i ] ) {
                prev = std::max( ++prev, cnt );
                ++cnt;
            } else {
                prev = cnt;
                cnt = 0;
            }
            
            res = std::max( res, prev );
        }
        
        return res;
    }
};

class Solution {
public:
    // time O( sizeof( nums ) * sizeof( nums ) )
    // space O( 1 )
    int longestSubarray(vector<int>& nums)
    {
        int l{ 0 };
        int r{ 0 };
        int cnt{ 0 };
        bool is_w{ false };
        while( r < nums.size() ) {
            while( l <= r && is_w && !nums[ r ] ) {
                if( !nums[ l++ ] )
                    is_w = false;
            }
            
            cnt = std::max( cnt, r - l );
            if( !nums[ r++ ] )
                is_w = true;
        }
        
        return cnt;
    }
};
