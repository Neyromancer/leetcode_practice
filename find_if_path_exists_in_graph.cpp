class Solution {
    using graph_t = std::unordered_map<int, std::unordered_set<int>>;
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end)
    {
        if( start == end )
            return true;

        graph_t graph = fill_graph( edges );
        
        if( !graph.count( start ) || !graph.count( end ) )
            return false;
        
        std::vector<int> visited(n);
        return dfs( graph, start, end, visited );
    }
    
    graph_t fill_graph( const vector<vector<int>>& edges )
    {
        graph_t graph;
        for( const auto& vertex : edges ) {
            auto& neighbours1 = graph[ vertex[ 0 ] ];
            neighbours1.insert( vertex[ 1 ] );
            
            auto& neighbours2 = graph[ vertex[ 1 ] ];
            neighbours2.insert( vertex[ 0 ] );            
        }
        
        return graph;
    }
    
    bool dfs( const graph_t& graph, int start, int end, std::vector<int>& visited )
    {
        if( start == end  )
            return true;

        ++visited[ start ];
        const auto& neighbours = graph.at( start );
        if( neighbours.count( end ) )
            return true;
        
        for( auto node : neighbours ) {
            if( visited[ node ] )
                continue;
            
            if( dfs( graph, node, end, visited ) )
                return true;
        }
        
        // --visited[ start ];
        return false;
    }
};
