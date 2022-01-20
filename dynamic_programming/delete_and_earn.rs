impl Solution {
    // TC: O( max( sizeof( nums ), sizeof( count ) )
    // SC: O( sizeof( count ) )
    pub fn delete_and_earn(nums: Vec<i32>) -> i32 {
        let mut count = vec![ 0; 10001 ];
        for n in 0..nums.len() {
            let index: usize = nums[ n ] as usize;
            count[ index ] = count[ index ] + 1;
        }
        
        let mut prev = 0;
        let mut used = 0;
        let mut avoid = 0;
        for n in 0..count.len() {
            if count[ n ] == 0 {
                continue;
            }
            
            let val = std::cmp::max( avoid, used );
            if prev == n - 1 {
                used = n * count[ n ] + avoid;
                avoid = val;
            } else {
                used = n * count[ n ] + val;
                avoid = val;
            }

            prev = n;
        }
        
        let res = std::cmp::max( avoid, used );
        return res as i32;
    }
}
