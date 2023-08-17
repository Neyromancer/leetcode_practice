// link: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/
#include <vector>

class Solution {
public:
    /*
      TC: O(log N), where N == len(nums)
      SC: O(1)
    */
    int countNegative(const std::vector<int>& nums) {
        int l = 0;
        int r = nums.size();
        while (r - l > 1) {
            int m = l + (r - l) / 2;

            if (nums[m] < 0)
                l = m;
            else
                r = m;
        }

        if (nums[l] < 0)
            return l + 1;
        return 0;
    }

    /*
      TC: O(log N), where N == len(nums)
      SC: O(1)
    */
    int countPositive(const std::vector<int>& nums) {
        int l = -1;
        int r = nums.size() - 1;
        while (r - l > 1) {
            int m = l + (r - l) / 2;

            if (nums[m] > 0)
                r = m;
            else
                l = m;
        }

        if (nums[r] > 0)
            return nums.size() - r;
        return 0;
    }

    /*
      TC: O(log N), where N == len(nums)
      SC: O(1)
    */
    int maximumCount(std::vector<int>& nums) {
        int positives = countPositive(nums);
        int negatives = countNegative(nums);
        return static_cast<int>(std::max(positives, negatives));
    }
};
