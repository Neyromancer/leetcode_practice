// Bottom-Up implementation
impl Solution {

    // TC: O( n )
    // SC: O( 1 )
    pub fn fib(n: i32) -> i32 {
        if n <= 1 {
            return n;
        }
        
        let mut first = 0;
        let mut second = 1;
        for i in 2..n + 1 {
            let tmp = second + first;
            first = second;
            second = tmp;
        }
        second
    }
}

// Top-down implementatino
// TC: O( n )
// SC O( n )
impl Solution {
    pub fn fib(n: i32) -> i32 {
        if n == 0 {
            return 0;
        }
        
        if n == 1 {
            return 1;
        }
        
        Self::fib( n - 1 ) + Self::fib( n - 2 )
    }
}
