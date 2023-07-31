/**
  Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

  Descripton:
  Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

  If target is not found in the array, return [-1, -1].

  You must write an algorithm with O(log n) runtime complexity.


  Examples:
  1/
    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]

  2/
    Input: nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]

  3/
    Input: nums = [], target = 0
    Output: [-1,-1]
*/
/*

    TC: O(log N + log N), where N == len(nums)
    SC: O(1)
*/
vector<int> searchRange(vector<int>& nums, int target) {
    int l = -1;
    int r = nums.size();

    std::vector<int> result(2);
    // left bin search
    while (r - l > 1) {
        int m = l + (r - l) / 2;

        if (nums[m] < target) {
            l = m;
        } else {
            r = m;
        }
    }
    result[0] = r;
    if (r >= nums.size() || nums[r] != target)
        result[0] = -1;

    l = -1;
    r = nums.size();
    // right bin search
    while (r - l > 1) {
        int m = l + (r - l) / 2;

        if (nums[m] <= target) {
            l = m;
        } else {
            r = m;
        }
    }
    result[1] = l;
    if (l < 0 || nums[l] != target)
        result[1] = -1;

    return result;
}
