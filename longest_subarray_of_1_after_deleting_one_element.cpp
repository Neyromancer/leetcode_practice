// space: O( 1 )
// time: O( size ), size - array size
class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        int i = 0;
        int j = 0;
        int dist = 1;
        for( ; j < nums.size(); ++j ) {
            if( nums[ j ] == 0 ) --dist;
            if( dist < 0 && nums[ i++ ] == 0 ) ++dist;
        }
        
        return j - i - 1;
    }
};

// space: O( 1 )
// time O( N ), where N - size of the array
class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        int next = 0;
        int prev = 0;
        int res = 0;
        for( int i = 0; i < nums.size(); ++i ) {
            if( nums[ i ] == 1 ) {
                ++next;
                res = std::max( res, next + prev );
            } else {
                res = std::max( res, next + prev );
                prev = next;
                next = 0;
            }
        }
        
        if( next == nums.size() )
            return next - 1;
        
        return res;
    }
};

// Space O( 1 )
// time O( N ), N array size
class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        int res{ 0 };
        int j{ 0 };
        int skip{ 0 };
        for( int i = 0; i < nums.size(); ++i ) {
            skip += nums[ i ] == 0;
            if( skip > 1 )
                skip -= nums[ j++ ] == 0;
            
            res = std::max( res, i - j + 1 );
        }
        
        return res - 1;
    }
};
