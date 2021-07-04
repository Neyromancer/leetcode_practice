class Solution {
public:
    int find_right( const std::vector<int> &nums, int l, int val )
    {
        for( int i = l + 1; i < nums.size(); ++i )
            if( val == nums[ i ] )
                return i;

        return std::numeric_limits<int>::min();
    }

    // tim O( N ^ 2 ), where N == nums.size()
    // space O( 1 )
    vector<int> twoSum(vector<int>& nums, int target)
    {
        if( nums.empty() )
            return {};

        for( int i = 0; i < nums.size(); ++i ) {
            if( auto j = find_right( nums, i, target - nums[ i ] );
              j != std::numeric_limits<int>::min() ) {
                return { i, j };
            }
        }
        
        return {};
    }
};

class Solution {
public:
    // tim O( N ), where N == nums.size()
    // space O( N ), where N == nums.size
    vector<int> twoSum(vector<int>& nums, int target)
    {
        if( nums.empty() )
            return {};
        
        std::unordered_map<int, std::vector<int>> st;
        for( int i = 0; i < nums.size(); ++i )
            st[ nums[ i ] ].push_back( i );

        for( int i = 0; i < nums.size(); ++i ) {
            auto val = target - nums[ i ];
            if( st.count( val ) ) {
                if( st[ val ].size() > 1 )
                    return st[ val ];
                
                if( i == st[ val ].front() )
                    continue;
                
                return { i, st[ val ].front() };
            }
        }
        
        return {};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        std::unordered_map<int, int> st;
        for( int i = 0; i < nums.size(); ++i ) {
            auto val = target - nums[ i ];
            if( st.count( val ) ) {
                return { i, st[ val ] };
            }
            
            st[ nums[ i ] ] = i;
        }
        
        return {};
    }
};


