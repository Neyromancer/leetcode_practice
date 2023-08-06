/*
 TC: O(log N), where N == len(nums)
 SC: O(1)
*/
int search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size();
    while (r - l > 1) {
        int m = l + (r - l) / 2;

        if (target >= nums[m]) {
            if (target >= nums[l] && nums[m] < nums[l])
                r = m;
            else
                l = m;
        } else { // target < nums[m]
            if (target < nums[l] && nums[m] >= nums[l])
                l = m;
            else
                r = m;
        }
    }
    if (nums[l] != target)
        return -1;
    return l;
}
