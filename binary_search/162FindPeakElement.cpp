class Solution {
public:
    /*
          |
        1 2

          |
          |
        |
        2 1
        0 1 2

        l: 0, 0, 0
        r: 2, 1, 1
        m: 1, 1, 0
    
    */
    bool is_peak(const std::vector<int> &nums, int i) {
        if (i == 0)
            return nums[i] > nums[i + 1] && nums[i] > nums.back();

        if (i == nums.size() - 1)
            return nums[i] > nums[i - 1] && nums[i] > nums.front();

        return nums[i] > nums[i - 1] && nums[i] > nums[i + 1];
    }

    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;
            if (is_peak(nums, m))
                return m;

            if (nums[m] < nums[(m + 1) % nums.size()])
                l = m + 1;
            else 
                r = m;
        }

        return l;
    }
};
