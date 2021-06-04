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


// =======================================================================================================
// BFS:
