// Top-Down implementation
class Solution {
public:    
    vector<int> sortArray( vector<int>& nums ) {
        std::vector<int> storage( nums.size() );
        for( int i = 0; i < nums.size(); ++i )
            storage[ i ] = nums[ i ];
        sort( nums, 0, nums.size() - 1, storage );
        return nums;
    }
    
    void sort( vector<int>& nums, int l, int r, vector<int>& storage ) {
        if( r <= l )
            return;
        
        int m = l + ( r - l ) / 2;
        sort( nums, l, m, storage );
        sort( nums, m + 1, r, storage );
        merge( nums, l, m, r, storage );
    }
    
    void merge( vector<int>& nums, int l, int m, int r, vector<int>& storage ) {
        if( r <= l )
            return;

        for( int i = l; i <= r; ++i )
            storage[ i ] = nums[ i ];

        // storage: 5 2 3 1
        // nums: 2 5 1 3
        // l = 0, m = 1, r = 3
        int ri = m + 1;
        int li = l;
        for( int i = l; i <= r; ++i ){
            if( li > m ) {
                nums[ i ] = storage[ ri++ ];
            } else if( ri > r ) {
                nums[ i ] = storage[ li++ ];
            } else if( storage[ li ] < storage[ ri ] ) {
                nums[ i ] = storage[ li++ ];
            } else {
                nums[ i ] = storage[ ri++ ];
            }
        }
    }
};

// Bottom-Up implementation
class Solution {
public:
    vector<int> sortArray(vector<int>& nums)
    {
        int size = nums.size();
        std::vector<int> aux( nums.size() );
        for( int sz = 1; sz < size; sz = sz + sz ) {
            for( int lo = 0; lo < size - sz; lo += sz + sz ) {
                merge( nums, aux, lo, lo + sz - 1, std::min( lo + sz + sz - 1, size - 1 ) );
            }
        }

        return nums;
    }
    
    void merge( std::vector<int>& nums, std::vector<int>& aux, int lo, int mid, int hi ) {
        if( lo >= hi )
            return;
        
        for( int i = lo; i <= hi; ++i )
            aux[ i ] = nums[ i ];
        
        int i = lo;
        int j = mid + 1;
        for( int k = lo; k <= hi; ++k ) {
            if( i > mid ) {
                nums[ k ] = aux[ j++ ];
            } else if( j > hi ) {
                nums[ k ] = aux[ i++ ];
            } else if( aux[ i ] > aux[ j ] ) {
                 nums[ k ] = aux[ j++ ];
            } else {
                nums[ k ] = aux[ i++ ];
            }
        }
    }
};

// quick sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums)
    {
        std::random_device rd;
        std::mt19937 gen{ rd() };
        std::shuffle( std::begin( nums ), std::end( nums ), gen );
        sort( nums, 0, nums.size() - 1 );
        return nums;
    }
    
    void sort( std::vector<int>& nums, int lo, int hi ) {
        if( lo >= hi )
            return;
        
        int j = partition( nums, lo, hi );
        sort( nums, lo, j - 1 );
        sort( nums, j + 1, hi );
    }
    
    int partition( std::vector<int>& nums, int lo, int hi ) {        
        int i = lo;
        int j = hi + 1;
        while( true ) {
            while( nums[ ++i ] < nums[ lo ] ) {
                if( i == hi )
                    break;
            }
            
            while( nums[ lo ] < nums[ --j ] ) {
                if( j == lo )
                    break;
            }
            
            if( i >= j ) break;
            std::swap( nums[ i ], nums[ j ] );
        }
        
        std::swap( nums[ lo ], nums[ j ] );
        return j;
    }
};
