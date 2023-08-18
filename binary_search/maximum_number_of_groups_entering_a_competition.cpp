// Link: https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/description/

#include <cstdint>
#include <vector>

class Solution {
public:
    /*
      TC: O(1)
      SC: O(1)
    */
    std::uint64_t countPeopleInGroups(std::uint64_t groups) {
        return groups * (groups + 1) / 2;
    }

    /*
      TC: O(log N), where N == len(grades)
      SC: O(1)
    */
    int maximumGroups(std::vector<int>& grades) {
        int l = 1;
        int r = grades.size();

        while (r - l > 1) {
            std::uint64_t  m = l + (r - l) / 2;

            if (countPeopleInGroups(m) > grades.size()) {
                r = m;
            } else {
                l = m;
            }
        }

        return l;
    }
};
