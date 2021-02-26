// space O( N )
// time O( log N )
class MyCalendar {
    std::list<std::pair<int,int>> storage;
public:
    MyCalendar() = default;
    
    bool book(int start, int end) 
    {
        if( is_overlap( start, end ) )
            return false;

        insert( start, end );

        return true;
    }
    
    bool is_overlap( int first, int last, int start, int end )
    {
        if( ( start <= first && first < end ) || 
            ( start > first && start < last ) ) {
            return true;
        } else if( ( end > first && end < last ) ||
                   ( last < end && last > start ) ) {
            return true;
        }
        
        return false;
    }
    
    bool is_overlap( int start, int end ) {
        if( storage.empty() )
            return false;
        
        auto lit = std::begin( storage );
        auto rit = storage.rbegin();
        
        int l = std::distance( lit, std::begin( storage ) );
        int r = storage.size() - std::distance( rit, storage.rbegin() );
        while( l <= r ) {
            int mid = l + ( r - l ) / 2;
            const auto &[ first, last ] = *std::next( std::begin( storage ), mid );           
            if( is_overlap( first, last, start, end ) )
                return true;
            
            if( end <= first ) {
                r = mid - 1;
            } else if( start >= last ) {
                l = mid + 1;
            } else {
                return true;
            }
        }

        return false;
    }
    
    void insert( int start, int end ) {
        if( storage.empty() ) {
            storage.emplace_back( start, end );
            return;
        }

        auto lit = std::begin( storage );
        if( lit->first >= end ) {
            storage.emplace_front( start, end );
            return;
        }

        auto rit = std::rbegin( storage );
        if( rit->second <= start ) {
            storage.emplace_back( start, end );
            return;
        }
        
        int l = std::distance( lit, std::begin( storage ) );
        int r = storage.size() - std::distance( rit, storage.rbegin() );

        while( l <= r ) {
            int mid = l + ( r - l ) / 2;
            const auto &[ first, last ] = *std::next( std::begin( storage ), mid );
            if( end <= first )
                r = mid - 1;
            else if( start >= last )
                l = mid + 1;
        }
        
        storage.emplace( std::next( std::begin( storage ), l ), start, end );
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */


// Time complexity O( N )
// Space complexity O( N )
class MyCalendar {
    std::forward_list<std::pair<int,int>> storage;
public:
    MyCalendar() = default;
    
    bool book(int start, int end) {
        if( is_intersect( start, end ) )
            return false;
        
        insert( start, end );
        return true;
    }
    
    bool is_intersect( int start, int end ) {
        if( storage.empty() )
            return false;
        
        for( const auto &[ first, last ] : storage ) {
            if( ( start <= first && first < end ) ||
                ( start > first && start < last ) ) {
                // std::cout << "here" << std::endl;
                return true;
            } else if( ( end > first && end < last ) || 
                     ( last < end && last > start ) ) {
                return true;
            }
            
        }

        return false;
    }
    
    void insert( int start, int end ) {
        if( storage.empty() ) {
            storage.emplace_front( start, end );
            return;
        }
        
        auto it = std::begin( storage );
        if( it->first > end ) {
            storage.emplace_front( start, end );
            return;
        }
        
        auto jt = std::begin( storage );
        for( ; it != std::end( storage ); ++it ) {
            if( it->first > end )
                break;
            
            jt = it;
        }
        
        storage.emplace_after( jt, start, end );
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
