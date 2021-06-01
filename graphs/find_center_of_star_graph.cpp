class Solution {
public:
    // time O( N ), where N == edges.size();
    // space O( N ), where N == edges.size()
    int findCenter(vector<vector<int>>& edges)
    {
        std::unordered_map<int,int> st;
        for( const auto &edge : edges ) {
            ++st[ edge[ 0 ] ];
            ++st[ edge[ 1 ] ];
        }
        
        for( const auto &[ node, cnt ] : st ) {
            if( cnt == edges.size() )
                return node;
        }
        
        return -1;
    }
};

class Solution {
public:
    // time O( 1 )
    // space O( 1 )
    int findCenter(vector<vector<int>>& edges)
    {
        return edges[ 0 ][ 0 ] == edges[ 1 ][ 0 ] || edges[ 0 ][ 0 ] == edges[ 1 ][ 1 ] ?
            edges[ 0 ][ 0 ] : edges[ 0 ][ 1 ];
    }
};
