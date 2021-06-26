class Solution {
public:
    // time complexity O(2^N), where N == graph's nodes
    // space colplexity O( N ), where N == graph's nodes
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        std::vector<std::vector<int>> res;
        std::vector<int> vc;
        vc.push_back( 0 ); // O( 1 )
        for( int node : graph[ 0 ] ) {
            walk( graph, res, vc, node );
        }
        
        return res;
    }
    
    void walk( const std::vector<std::vector<int>> &graph, 
        std::vector<std::vector<int>> &res, std::vector<int> vc, int node )
    {
        vc.push_back( node ); // O( 1 )
        if( node == graph.size() - 1 ) { // O( 1 )
            res.push_back( vc ); // O( 1 )
            return;
        }
        
        for( int n : graph[ node ] ) // O ( 1 )
            walk( graph, res, vc, n );
    }
};
