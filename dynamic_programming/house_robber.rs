// Bottom-up implementation
impl Solution {
    // TC: O( sizeof( nums ) )
    // SC: O( 1 )
    pub fn rob(mut nums: Vec<i32>) -> i32 {
        if nums.len() == 1 {
            return nums[ 0 ];
        }
        
        if nums.len() == 2 {
            return if nums[ 0 ] > nums[ 1 ] { nums[ 0 ] } else { nums[ 1 ] };
        }
        
        nums[ 2 ] += nums[ 0 ];
        for i in 3..nums.len() {
            nums[ i ] += std::cmp::max( nums[ i - 2 ], nums[ i - 3 ] );
        }
        
        let sz = nums.len();
        return std::cmp::max( nums[ sz - 1 ], nums[ sz - 2 ] );
    }
}

// Top-down implementation
impl Solution {
    pub fn rob(mut nums: Vec<i32>) -> i32 {
        if nums.len() == 1 {
            return nums[ 0 ];
        }
        
        if nums.len() == 2 {
            return std::cmp::max( nums[ 0 ], nums[ 1 ] );
        }
        
        nums[ 2 ] += nums[ 0 ];
        Self::check_houses( &mut nums, 3 );
        return std::cmp::max( nums[ nums.len() - 1 ], nums[ nums.len() - 2 ] );
    }
    
    pub fn check_houses( nums: &mut Vec<i32>, i: usize ) {
        if i >= nums.len() {
            return;
        }
        
        nums[ i ] += std::cmp::max( nums[ i - 2 ], nums[ i - 3 ] );
        Self::check_houses( nums, i + 1 );
    } 
}
