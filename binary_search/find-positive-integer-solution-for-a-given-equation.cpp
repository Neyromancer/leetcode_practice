#include <vector>

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    /*
        TC: O(1)
        SC: O(1)
    */
    std::vector<std::vector<int>> findSolution(CustomFunction& customfunction, int z) {
        std::vector<std::vector<int>> result;
        for (int i = 1; i <= 1000; ++i) {
            int l = 1;
            int r = 1001;

            while (r - l > 1) {
                int m = l + (r - l) / 2;

                if (customfunction.f(i, m) > z) {
                    r = m;
                } else {
                    l = m;
                }
            }

            if (customfunction.f(i, l) == z)
                result.push_back({i, l});
        }
        return result;
    }
};
