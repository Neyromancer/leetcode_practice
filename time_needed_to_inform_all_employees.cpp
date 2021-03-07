// space: O( employees )
// time: T( employees )
class Solution {
    std::unordered_map<int, std::vector<int>> hierarchy;
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        build_hierarchy( manager );
        return walk( headID, informTime );
    }
    
    int walk( int headID, std::vector<int>& informTime )
    {
        if( informTime[ headID ] == 0 )
            return 0;
        
        int mins{ INT_MIN };
        for( auto &emp_id : hierarchy[ headID ] )
            mins = std::max( mins, walk( emp_id, informTime ) );
        
        return informTime[ headID ] + mins;  
    }
    
    void build_hierarchy( const std::vector<int> &managers )
    {
        for( int i = 0; i < managers.size(); ++i ) {
            if( managers[ i ] < 0 )
                continue;
            
            hierarchy[ managers[ i ] ].push_back( i );
        }
    }
};

// Time O( N )
// Space O( 1 )
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        int mins{ 0 };
        for( int i = 0; i < manager.size(); ++i )
            mins = std::max( mins, dfs( i, manager, informTime ) );
        return mins;
    }
    
    int dfs( int id, std::vector<int> &manager, std::vector<int> &informTime )
    {
        if( manager[ id ] != -1 ) {
            informTime[ id ] += dfs( manager[ id ], manager, informTime );
            manager[ id ] = -1;
        }
        
        return informTime[ id ];
    }
};
