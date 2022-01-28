use std::collections::HashSet;
// Top-Down approach with memoization
impl Solution {
    // TC: O( nums.len() )
    // SC: O( numss.len() )
    pub fn can_partition(nums: Vec<i32>) -> bool {
        let target: i32 = nums.iter().sum();
        if target % 2 != 0 {
            return false;
        }

        let mut cache: &mut HashSet<i32> = &mut HashSet::new();
        
        Self::dfs( &nums, cache, target / 2, 0 )
    }
    
    pub fn dfs( nums: &Vec<i32>, mut cache: &mut HashSet<i32>, target: i32, index: usize ) -> bool {
        if target < 0 {
            return false;
        }
        
        if target == 0 {
            return true;
        }
        
        if cache.contains( &target ) {
            return false;
        }
        
        cache.insert( target );
        for i in (index + (1 as usize))..nums.len() {
            if Self::dfs( nums, cache, target - nums[ i ], i ) ||
               Self::dfs( nums, cache, target, i ) {
                   return true;
            }
        }
        
        return false;
    }
}

// Bottom-Up approach/tabulation
impl Solution {
    // TC: O( sumof( nums ) * sizeof( nums ) )
    // SC: O( sumof( nums ) * sizeof( nums ) )
    pub fn can_partition(nums: Vec<i32>) -> bool {
        let tsum:i32 = nums.iter().sum();
        if tsum % 2 != 0 {
            return false;
        }
        
        let target: usize = ( tsum / 2 ) as usize;
        let sz = nums.len();
        let mut st: Vec<Vec<bool>> = vec![ vec![ false; target + 1 as usize ]; sz + 1 as usize ];
        for i in 0..sz {
            st[ i ][ 0 ] = true;
        }
        
        for i in 1..( sz + ( 1 as usize ) ) {
            let curr: usize = nums[ i - 1 ] as usize;
            for j in 0..( target + ( 1 as usize ) ) {
                if curr > j {
                    st[ i ][ j ] = st[ i - 1 ][ j ];
                } else {
                    st[ i ][ j ] = st[ i - 1 ][ j ] || st[ i - 1 ][ j - curr ];
                }
            }
        }

        return st[ sz ][ target ];
    }
}

impl Solution {
    // TC: O( sumof( nums ) * sizeof( nums ) )
    // SC: O( sumof( nums ) )
    pub fn can_partition(nums: Vec<i32>) -> bool {
        let mut target: i32 = nums.iter().sum();
        if target % 2 != 0 {
            return false;
        }
        
        target = target / 2;
        let mut st: Vec<bool> = vec![ false; (target + 1) as usize ];
        st[ 0 ] = true;
        for cur in (nums) {
            for j in (1..=target).rev() {
                if cur > j {
                    break;
                }
                
                st[ j as usize ] = st[ j as usize ] || st[ ( j - cur ) as usize ];
            }
        }
        
        return st[ target as usize];
    }
}
