#include <vector>

class Solution {
public:
    /*    
        TC: O(N log N), where N == len(stones)
        SC: O(N log N), where N == len(stones)
    */
    int maxJump(std::vector<int>& stones) {
        int l = 0;
        int r = stones.back();

        while (r - l > 1) {
            int m = l + (r - l) / 2;

            if (isPathPossible(stones, m)) { // TC: O(N), SC: O(N), where N == len(stones)
                r = m; 
            } else {
                l = m;
            }
        }
        return r;
    }

    /*
        TC: O(N), where N == len(stones)
        SC: O(N), where N == len(stones)
    */
    bool isPathPossible(const std::vector<int>& stones, int maxJumpDistance) {
        std::vector<bool> used(stones.size());
        int lastVisitedIndex = 0;

        for (int i = 0; i < stones.size(); ++i) {
            int j = i;
            while (j >= 0 && stones[j] - stones[lastVisitedIndex] > maxJumpDistance) {
                --j;
                if (j == lastVisitedIndex)
                    return false;

                lastVisitedIndex = j;
                used[lastVisitedIndex] = true;
            }
        }

        used.back() = true;
        lastVisitedIndex = stones.size() - 1;
        for (int i = lastVisitedIndex - 1; i >= 0; --i) {
            if (!used[i]) {
                if (stones[lastVisitedIndex] - stones[i] > maxJumpDistance)
                    return false;
                lastVisitedIndex = i;
            }
        }
        return true;
    }
};
