use std::collections::HashSet;

    fn are_connected( graph: &Vec<Vec<i32>>, mut seen: &mut HashSet<i32>, val: i32, target: i32 ) -> bool {
        if !seen.contains( &val ) {
            seen.insert( val );
            if val == target {
                return true;
            }
            
            let index: usize = val as usize;
            for i in 0..graph[ index ].len() {
                if are_connected( &graph, &mut seen, graph[ index ][ i ], target ) {
                    return true;
                }
            }
        }
        
        return false;
    }
impl Solution {    
    pub fn find_redundant_connection(edges: Vec<Vec<i32>>) -> Vec<i32> 
    {
        let mut tmp: Vec<i32> = Vec::new();
        let mut graph = vec![ tmp; 1001 ];
        let mut res = vec![ 0; 2 ];
        
        for i in 0..edges.len() {
            let mut seen = HashSet::new();
            if i != 0 && are_connected( &graph, &mut seen, edges[ i ][ 0 ], edges[ i ][ 1 ] ) {
                res[ 0 ] = edges[ i ][ 0 ];
                res[ 1 ] = edges[ i ][ 1 ];
            }
            
            graph[ edges[ i ][ 0 ] as usize ].push( edges[ i ][ 1 ] );
            graph[ edges[ i ][ 1 ] as usize ].push( edges[ i ][ 0 ] );
        }
        
        return res;
    }
}
