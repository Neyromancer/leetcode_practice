impl Solution {
    pub fn tribonacci(n: i32) -> i32
    {
        if n <= 1 {
            return n;
        }
        
        if n == 2 {
            return 1;
        }
        
        let mut first = 0;
        let mut second = 1;
        let mut third = 1;
        for i in 3..n + 1 {
            let tmp = first + second + third;
            first = second;
            second = third;
            third = tmp;
        }
        
        return third;
    }
}
