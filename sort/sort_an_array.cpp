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
