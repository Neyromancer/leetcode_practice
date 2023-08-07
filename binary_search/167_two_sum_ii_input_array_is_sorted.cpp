class Solution {
public:
    /*
        TC: O(log N), where N == len(numbers)
        SC: O(1)
    */
    int search(const std::vector<int> &numbers, int target, int i) {
        int l = i + 1;
        int r = numbers.size();

        while (r - l > 1) {
            int m = l + (r - l) / 2;

            if (numbers[m] > target) {
                r = m;
            } else {
                l = m;
            }
        }

        if (numbers[l] != target)
            return -1;
        return l;
    }

    /*
        TC: O(N log N), where N == len(numbers)
        SC: O(1)
    */
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size(); ++i) {
            if (i && numbers[i] == numbers[i - 1])
                continue;
            
            int index = search(numbers, target - numbers[i], i);
            if (index < 0)
                continue;

            return {i + 1, index + 1};
        }
        return {};
    }
};
