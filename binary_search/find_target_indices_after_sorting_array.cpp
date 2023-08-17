// Link: https://leetcode.com/problems/find-target-indices-after-sorting-array/description/

#include <algorithm>
#include <vector>

class Solution {
public:
    /*
      SC: O(N log N), where N == len(nums)
      TC: O(log N), where N == len(nums)
    */
    std::vector<int> targetIndices(std::vector<int>& nums, int target) {
        std::sort(std::begin(nums), std::end(nums)); // SC: O(N log N)/ TC: O(log N), where N == len(nums)
        std::vector<int> result;

        int l = -1;
        int r = nums.size() - 1;
        while (r - l > 1) {
            int m = l + (r - l) / 2;

            if (nums[m] >= target)
                r = m;
            else
                l = m;
        }
        if (nums[r] == target)
            result.push_back(r); // O(1)

        {
            int l = 0;
            int r = nums.size(); // O(1)
            while (r - l > 1) {
                int m = l + (r - l) / 2;

                if (nums[m] > target) {
                    r = m;
                } else {
                    l = m;
                }
            }
            
            if (nums[l] == target) {
                int i = result.empty() ? l : result.front() + 1; // O(1)
                while (i <= l) {
                    result.push_back(i); // O(1)
                    ++i;
                }
            }
        }

        return result;
    }
};
