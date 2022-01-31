impl Solution {
    pub fn find_target_sum_ways(nums: Vec<i32>, target: i32) -> i32 {
        if nums.len() == 0 {
            return 0;
        }
        
        Self::cnt_ways( &nums, target, 0 as usize, 0 )
    }
    
    pub fn cnt_ways( nums: &[i32], target: i32, i: usize, res: i32 ) -> i32 {
        if i >= nums.len() {
            if res == target {
                return 1;
            }
            
            return 0;
        }
        
        Self::cnt_ways( nums, target, i + 1 as usize, res + nums[ i ] ) +
        Self::cnt_ways( nums, target, i + 1 as usize, res - nums[ i ] )
    }
}
