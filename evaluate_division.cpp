class Solution {
public:
    
    // time O( sizeof( equations ) * sizeof( queries ) )
    // space O( sizeof( equations ) )
    using graph_t = std::unordered_map<std::string, std::unordered_map<std::string, double>>;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        graph_t graph = fill_graph( equations, values );
        std::vector<double> res( queries.size() );
        for( int i = 0; i < queries.size(); ++i ) {
            auto devidend = queries[ i ][ 0 ];
            auto diviser = queries[ i ][ 1 ];
            if( !graph.count( devidend ) || !graph.count( diviser ) ) {
                res[ i ] = -1;
            } else if( devidend == diviser ) {
                res[ i ] = 1;
            } else {
                std::unordered_set<std::string> visited;
                res[ i ] = dfs( graph, devidend, diviser, visited, 1 );
            }
        }
        
        return res;
    }
    
    // time O( sizeof( equations ) )
    // space O( 1 )
    graph_t fill_graph( const std::vector<std::vector<std::string>>& equations, const std::vector<double>& values ) {
        graph_t graph;
        for( int i = 0; i < equations.size(); ++i ) {
            auto devidend = equations[ i ][ 0 ]; // O( 1 )
            auto diviser = equations[ i ][ 1 ]; // O( 1 )
            auto quotient = values[ i ]; // O( 1 )
            auto& st1 = graph[ devidend ]; // O( 1 )
            st1[ diviser ] = quotient; // O( 1 )
            
            auto& st2 = graph[ diviser ]; // O( 1 )
            st2[ devidend ] = 1 / quotient; // O( 1 )
        }
        
        return graph;
    }
    
    // time O( sizeof( graph ) )
    // space O( sizeof( graph ) )
    double dfs( const graph_t& graph, const std::string& devidend, const std::string& diviser, std::unordered_set<std::string>& visited, double accume ) {
        visited.insert( devidend );
        double res{ -1.0 };
        
        const auto& neighbours = graph.at( devidend ); // O( 1 )
        if( neighbours.count( diviser ) ) { // O( 1 )
            res = accume * neighbours.at( diviser ); // O( 1 )
        } else {
            for( const auto& [ next, weight ] : neighbours ) { // O( sizeof( neighbours ) )
                if( visited.count( next ) ) // O( 1 )
                    continue;
                
                res = dfs( graph, next, diviser, visited, accume * weight );
                if( res != -1 )
                    break;
            }
        }
        
        visited.erase( devidend );
        return res;
    }
};

/*
[["a","b"],["b","c"]]
[2.0,3.0]
[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
*/
class UnionFind {
    std::unordered_map<std::string, std::pair<std::string, double>> parents;
public:
    bool contain( const std::string& id )
    {
        return parents.count( id ) != 0;
    }
    
    void unite( const std::string& id1, const std::string& id2, double val )
    {
        const auto& [ index1, weight1 ] = find( id1 );
        const auto& [ index2, weight2 ] = find( id2 );
        if( index1 == index2 )
            return;
        
        parents[ index1 ] = std::make_pair( index2, ( weight2 * val ) / weight1 );
    }
    
    std::pair<std::string, double> find( const std::string& id )
    {
        if( !contain( id ) )
            parents[ id ] = std::make_pair( id, 1.0 );
        
        const auto& [ node, weight ] = parents[ id ];
        if( node != id ) {
            const auto& [ root, rweight ] = find( node );
            parents[ id ] = std::make_pair( root, rweight * weight );
        }
        
        return parents[ id ];
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        UnionFind uf;
        for( int i = 0; i < equations.size(); ++i ) {
            auto divident = equations[ i ][ 0 ];
            auto divisor = equations[ i ][ 1 ];
            auto val = values[ i ];
            uf.unite( divident, divisor, val );
        }
        
        std::vector<double> res( queries.size() );
        for( int i = 0; i < queries.size(); ++i ) {
            const auto& divident = queries[ i ][ 0 ];
            const auto& divisor = queries[ i ][ 1 ];
            if( !uf.contain( divident ) || !uf.contain( divisor ) ) {
                res[ i ] = -1.0;
                continue;
            }
            
            const auto& [ divident_root, divident_weight ] = uf.find( divident );
            const auto& [ divisor_root, divisor_weight ] = uf.find( divisor );
            if( divident_root != divisor_root ) {
                res[ i ] = -1.0;
                continue;                
            }
            
            res[ i ] = divident_weight / divisor_weight;
        }
        
        return res;
    }
};
