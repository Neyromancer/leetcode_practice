#import <cstdint>
/*
Link: https://leetcode.com/problems/sqrtx/description/

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

Example:

1/
Input: x = 4
Output: 2

2/
Input: x = 8
Output: 2

  TC: O(log N), where N == x
  SC: O(1)
*/
int mySqrt(int x) {
    if (x == 1 || x == 0)
        return x;

    std::uint64_t l = 0;
    std::uint64_t r = x;
    while (r - l > 1) {
        std::uint64_t m = l + (r - l) / 2;
        if (m == x / m)
            return m;

        if (m  > x / m) {
            r = m;
        } else {
            l = m;
        }
    }
    return l;
}
