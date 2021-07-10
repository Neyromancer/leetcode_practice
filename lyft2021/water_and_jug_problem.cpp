class Solution {
public:
    // time O( jug1Capacity x jug2Capacity )
    // space O( jug1Capacity x jug2Capacity )
    bool canMeasureWater( int jug1Capacity, int jug2Capacity, int targetCapacity )
    {
        std::unordered_set<std::string> visited;
        std::queue<std::pair<int,int>> q;
        q.push( { 0, 0 } ); // O( 1 )
        visited.insert( 0 + ", " + 0 ); // O( 1 )
        while( !q.empty() ) {
            auto [ j1, j2 ] = q.front(); // O( 1 )

            if( j1 + j2 == targetCapacity )
                return true;

            visited.insert( j1 + ", " + j2 ); // O( 1 )
            q.pop(); // O( 1 )
            
            // j1 -> j2
            int jug1 = j1 - std::min( j1, jug2Capacity - j2 );
            int jug2 = j2 + std::min( j1, jug2Capacity - j2 );
            
            if( !visited.count( jug1 + ", " + jug2 ) ) // O( 1 )
                q.push( { jug1, jug2 } ); // O( 1 )
            
            // j2 -> j1
            jug2 = j2 - std::min( j2, jug1Capacity - j1 );
            jug1 = j1 + std::min( j2, jug1Capacity - j1 );
            
            if( !visited.count( jug1 + ", " + jug2 ) ) // O( 1 )
                q.push( { jug1, jug2 } ); // O( 1 )
            
            // empty j1
            jug1 = 0;
            jug2 = j2;
            if( !visited.count( jug1 + ", " + jug2 ) ) // O( 1 )
                q.push( { jug1, jug2 } ); // O( 1 )
            
            // empty j2
            jug1 = j1;
            jug2 = 0;
            if( !visited.count( jug1 + ", " + jug2 ) ) // O( 1 )
                q.push( { jug1, jug2 } ); // O( 1 )
            
            // fill j1
            jug1 = jug1Capacity;
            jug2 = j2;
            if( !visited.count( jug1 + ", " + jug2 ) ) // O( 1 )
                q.push( { jug1, jug2 } ); // O( 1 )
            
            // fill j2
            jug2 = jug2Capacity;
            jug1 = j1;
            if( !visited.count( jug1 + ", " + jug2 ) ) // O( 1 )
                q.push( { jug1, jug2 } ); // O( 1 )
        }
        
        return false;
    }
};
