#include <vector>

class Solution {
public:
    /*
        TC: O(log N), where N == len(grid[0])
        SC: O(1)
    */
    int countNegativesInRow(const std::vector<int> &row) {
        int l = -1;
        int r = row.size();
        while (r - l > 1) {
            int m = l + (r - l) / 2;

            if (row[m] >= 0) {
                l = m;
            } else {
                r = m;
            }
        }
        return row.size() - r;
    }

    /*
        TC: O(M log N), where M == len(grid), N == len(grid[0])
        SC: O(1)
    */
    int countNegatives(std::vector<std::vector<int>>& grid) {
        int cnt_negatives = 0;
        for (const auto& row : grid) {
            cnt_negatives += countNegativesInRow(row); // O(log N), where N == len(grid[0])
        }
        return cnt_negatives;
    }
};
