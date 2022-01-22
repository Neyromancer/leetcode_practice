// Bottom-up implementation
impl Solution {
    // TC: O( target * nums.len() )
    // SC: O( target + 1 )
    pub fn combination_sum4(nums: Vec<i32>, target: i32) -> i32 {
        let mut dp = vec![0; (target + 1) as usize];
        dp[ 0 ] = 1;
        for t in 1..=target {
            for n in &nums {
                if t as i32 - *n >= 0 {
                    dp[ t as usize ] += dp[ (t - *n) as usize ];
                }
            }
        }
        
        return dp[target as usize];
    }
}
