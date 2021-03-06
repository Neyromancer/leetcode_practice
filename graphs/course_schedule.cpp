// DFS:
class Solution {
public:
    // time O( N^2 ), where N == prerequisites.size()
    // space O( N ), where N == prerequisites.size()
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        std::unordered_map<int, std::vector<int>> st;
        for( const auto &node : prerequisites ) {
            if( node[ 1 ] == node[ 0 ] || !walk( st, node[ 1 ], node[ 0 ] ) )
                return false;
            
            st[ node[ 1 ] ].push_back( node[ 0 ] );
        }
        
        return true;
    }
    
    bool walk( const std::unordered_map<int, std::vector<int>> &st, int searched, int key )
    {
        if( st.count( key ) == 0 )
            return true;
 
        // time O( N ), where N == prerequisites.size()
        for( auto el : st.at( key ) ) {
            if( el == searched )
                return false;
            
            if( !walk( st, searched, el ) )
                return false;
        }

        return true;
    }
};

class Solution {
public:
    // time O( N * M ), where N == prerequisites.size(), M == numCourses
    // space O( N + M ), where N == prerequisites.size(), M == numCourses
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        // space O( N )
        // time O( 1 )
        std::unordered_map<int, std::vector<int>> graph = build_graph( prerequisites );
        // space O( M )
        std::vector<bool> move_continue( numCourses );
        // space O( M )
        std::vector<bool> done( numCourses );
        for( int i = 0; i < numCourses; ++i ) { // O( M )
            // space O( N ) as recursion
            if( !done[ i ] && has_sycle( graph, move_continue, done, i ) )
                return false;
        }
        
        return true;
    }
    
    std::unordered_map<int, std::vector<int>> build_graph( const vector<vector<int>> &prerequisites )
    {
        // space O( N )
        std::unordered_map<int, std::vector<int>> res;
        for( const auto &node : prerequisites ) // time O( N )
            res[ node[ 1 ] ].push_back( node[ 0 ] ); // time amortized O( 1 ) 
        
        return res;
    }
    
    bool has_sycle( const std::unordered_map<int, std::vector<int>> &graph, 
                    std::vector<bool> &move_continue, std::vector<bool> &done, int node )
    {
        if( move_continue[ node ] ) // time O( 1 )
            return true;
        
        if( done[ node ] ) // time O( 1 )
            return false;
        
        move_continue[ node ] = done[ node ] = true; // time O( 1 )
        if( graph.count( node ) ) { // time O( 1 ) in average, but O( N ), in the worst case
            for( int el : graph.at( node ) ) // time O( N ), where N == graph.size()
                if( has_sycle( graph, move_continue, done, el ) )
                    return true;
        }
        
        move_continue[ node ] = false; // time O( 1 )
        return false;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        std::vector<std::vector<int>> graph = create_graph( numCourses, prerequisites );
        std::vector<bool> visited( numCourses );
        std::vector<bool> to_visit( numCourses );
        for( int i = 0; i < numCourses; ++i ) {
            if( !visited[ i ] && !acycle( graph, visited, to_visit, i ) )
                return false;
        }
        
        return true;
    }
    
    std::vector<std::vector<int>>
    create_graph( int numCourses, const vector<vector<int>> &prerequisites )
    {
        std::vector<std::vector<int>> res( numCourses );
        for( const auto &courses : prerequisites )
            res[ courses[ 1 ] ].push_back( courses[ 0 ] );
        
        return res;
    }
    
    bool acycle( const std::vector<std::vector<int>> &graph,
                 std::vector<bool> &visited, std::vector<bool> &to_visit, int node )
    {
        if( to_visit[ node ] )
            return false;
        
        if( visited[ node ] )
            return true;
        
        visited[ node ] = to_visit[ node ] = true;
        for( auto n : graph[ node ] )
            if( !acycle( graph, visited, to_visit, n ) )
                return false;
        
        to_visit[ node ] = false;
        return true;
    }
};

// =======================================================================================================
// BFS:

/*
5
[[1,4],[2,4],[3,1],[3,2]]
2
[[1,0]]
3
[[1,0],[0,2],[2,1]]
2
[[1,0],[0,1]]
20
[[0,10],[3,18],[5,5],[6,11],[11,14],[13,1],[15,1],[17,4]]
8
[[1,0],[2,6],[1,7],[6,4],[7,0],[0,5]]
*/
class Solution {
public:
    /*
    2
        [[1,0]]
        graph:
          1: 0
         
         indegree: 1 0
                   0 1 
         q
    */
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites )
    {
        if( prerequisites.size() == 1 && numCourses != 1 )
            return true;
        else if( prerequisites.size() == 1 && numCourses == 2 )
            return false;
        std::unordered_map<int, std::vector<int>> graph = create_graph( prerequisites );
        std::vector<int> indegree = create_indegree( graph, numCourses );
        int cnt{ 0 };
        std::queue<int> q;
        for( int i = 0; i < numCourses; ++i ) {
            if( indegree[ i ] )
                continue;
            
            ++cnt;
            q.push( i );
            while( !q.empty() ) {
                auto node = q.front();
                q.pop();
                if( !graph.count( node ) )
                    continue;
                
                for( auto vertex : graph[ node ] ) {
                    if( --indegree[ vertex ] == 0 ) {
                        q.push( vertex );
                        ++cnt;
                        indegree[ vertex ] = -1;
                    }
                }
            }
        }
        
        // std::cout << "cnt = " << cnt << std::endl;
        // std::cout << "size = " << prerequisites.size() << std::endl;
        return cnt == numCourses;
    }

    std::unordered_map<int, std::vector<int>> 
    create_graph( const std::vector<std::vector<int>> &prerequisites )
    {
        std::unordered_map<int, std::vector<int>> graph;
        for( const auto &node : prerequisites )
            graph[ node[ 1 ] ].push_back( node[ 0 ] );
        
        return graph;
    }
    
    std::vector<int> create_indegree( const std::unordered_map<int, std::vector<int>> &graph,
                                     int numCourses )
    {
        std::vector<int> indegree( numCourses );
        for( const auto &[ v, dependencies ] : graph ) {
            if( indegree[ v ] < 0 )
                indegree[ v ] = 0;
            for( auto vertex : dependencies ) {
                if( indegree[ vertex ] < 0 )
                    indegree[ vertex ] = 0;

                ++indegree[ vertex ];
            }
        }
        
        return indegree;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites )
    {
        std::unordered_map<int, std::vector<int>> graph = create_graph( prerequisites );
        std::unordered_map<int, int> indegree = create_indegree( graph );
        int checked_nodes{ 0 };
        std::queue<int> q;
        for( auto &[ vertex, nedges ] : indegree ) {
            if( nedges )
                continue;
            
            q.push( vertex );
            while( !q.empty() ) {x
                auto node = q.front();
                q.pop();
                
                ++checked_nodes;
                for( auto v : graph[ node ] ) {
                    if( --indegree[ v ] == 0 ) {
                        q.push( v );
                        
                        indegree[ v ] = -1;
                        indegree[ node ] = -1;
                    }
                }
            }
        }
        
        return checked_nodes == graph.size();
    }
    
    std::unordered_map<int, std::vector<int>> create_graph( const vector<vector<int>> &prerequisites )
    {
        std::unordered_map<int, std::vector<int>> res;
        for( const auto &courses : prerequisites )
            res[ courses[ 1 ] ].push_back( courses[ 0 ] );
        
        return res;
    }
    
    std::unordered_map<int, int> 
    create_indegree( const std::unordered_map<int, std::vector<int>> &graph )
    {
        std::unordered_map<int, int> res;
        for( const auto &[ node, dependencies ] : graph ) {
            res[ node ];
            for( const auto &v : dependencies )
                ++res[ v ];
        }
        
        return res;
    }
};

class Solution {
public:
    // space O( N ), where N == numCourses
    // time O( N + M ), where M == prerequisites.size() and N == numCourses
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        std::vector<std::vector<int>> adjes( numCourses );
        std::vector<int> indegrees( numCourses, 0 );
        // O( M ), where M == prerequisites.size()
        for( const auto &courses : prerequisites ) {
            adjes[ courses[ 1 ] ].push_back( courses[ 0 ] );
            ++indegrees[ courses[ 0 ] ];
        }
        
        std::queue<int> q;
        // O( N ), where N == numCourses
        for( int i = 0; i < indegrees.size(); ++i ) {
            if( indegrees[ i ] )
                continue;
            
            q.push( i );
            while( !q.empty() ) {
                auto node = q.front();
                q.pop();
                --numCourses;
                
                for( auto n : adjes[ node ] ) {
                    if( --indegrees[ n ] == 0 ) {
                        q.push( n );
                        indegrees[ n ] = -1;
                        indegrees[ node ] = -1;
                    }
                }
            }
        }
        
        // std::cout << "numCourses " << numCourses << std::endl;
        return numCourses == 0;
    }
};
