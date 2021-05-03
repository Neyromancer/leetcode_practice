// space O( N )
// time O( N log M ), where N == tasks.size(), M == queue.size()
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) 
    {
        struct task_t {
            int index{ 0 };
            int enqueueTime{ 0 };
            int processingTime{ 0 };
        };
        
        // space O( N ), where N == tasks.size()
        std::vector<task_t> cpu_tasks( tasks.size() );
        for( int i = 0; i < tasks.size(); ++i ) {
            cpu_tasks[ i ].index = i;
            cpu_tasks[ i ].enqueueTime = tasks[ i ][ 0 ];
            cpu_tasks[ i ].processingTime = tasks[ i ][ 1 ];
        }
        
        // time O( N log N ), where N == cpu_tasks.size()
        std::sort( std::begin( cpu_tasks ), std::end( cpu_tasks ), 
                  []( const task_t &t1, const task_t &t2 ){
                      return ( ( t1.enqueueTime == t2.enqueueTime &&
                               t1.processingTime <= t2.processingTime ) || 
                          ( t1.enqueueTime < t2.enqueueTime ) );
                  } );
        
        auto cmp = []( const task_t &t1, const task_t &t2 ){
            return ( ( t1.processingTime > t2.processingTime ) ||
                     ( t1.processingTime == t2.processingTime && t1.index >= t2.index ) );
        };
        // space O( N ), where N == cpu_tasks.size()
        std::priority_queue<task_t, std::vector<task_t>, decltype( cmp )> q( cmp );
        int id{ 0 };
        // space O( N ), where N == cpu_tasks.size()
        std::vector<int> res( cpu_tasks.size() );
        int res_id{ 0 };
        while( id < cpu_tasks.size() ) {
            q.push( cpu_tasks[ id ] ); // O( log N ), where N == q.size()
            long time = cpu_tasks[ id++ ].enqueueTime;
            while( !q.empty() ) {
                auto node = q.top(); // O( 1 )
                q.pop(); // O( log N ), where N == q.size()
                res[ res_id++ ] = node.index; // O( 1 )
                time += node.processingTime;
                while( id < cpu_tasks.size() && time >= cpu_tasks[ id ].enqueueTime ) // O( 1 )
                    q.push( cpu_tasks[ id++ ] ); // O( log N ), where N == q.size()
            }
        }
        
        return res;
    }
};
