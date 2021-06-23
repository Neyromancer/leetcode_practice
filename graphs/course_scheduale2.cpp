// DFS ( topological sort ):

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        if( numCourses == 1 )
            return {0};

        std::vector<std::vector<int>> graph = create_graph( numCourses, prerequisites );
        std::vector<int> indegrees = create_indegrees( graph );
        
        std::queue<int> q;
        std::vector<int> res;
        for( int i = 0; i < indegrees.size(); ++i ) {
            if( indegrees[ i ] )
                continue;
            
            q.push( i );
            while( !q.empty() ) {
                auto node = q.front();
                q.pop();
                res.push_back( node );
                for( auto v : graph[ node ] ) {
                    if( --indegrees[ v ] == 0 ) {
                        q.push( v );
                        indegrees[ v ] = -1;
                        indegrees[ node ] = -1;
                    }
                }
            }
        }
        
        return ( res.size() == indegrees.size() ? res : std::vector<int>{} );
    }
    
    std::vector<std::vector<int>> create_graph( int numCourses, const vector<vector<int>> &prerequisites )
    {
        std::vector<std::vector<int>> res( numCourses );
        for( const auto &course : prerequisites )
            res[ course[ 1 ] ].push_back( course[ 0 ] );
        
        return res;
    }
    
    std::vector<int> create_indegrees( const std::vector<std::vector<int>> &graph ) 
    {
        std::vector<int> res( graph.size() );
        for( const auto &dependencies : graph ) {
            for( auto cource : dependencies )
                ++res[ cource ];
        }
        
        return res;
    }
};
