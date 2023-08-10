/*
Links: https://leetcode.com/problems/minimum-time-to-repair-cars/description/

You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.

You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.

Return the minimum time taken to repair all the cars.

Note: All the mechanics can repair the cars simultaneously.

Example:
1/ Input: ranks = [4,2,3,1], cars = 10
Output: 16
Explanation: 
- The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
- The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
- The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
- The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.

2/
Input: ranks = [5,1,8], cars = 6
Output: 16
Explanation: 
- The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5 minutes.
- The second mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
- The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.
*/

#include <cmath>
#include <vector>

class Solution {
public:
    /*
        TC: O(M), where M == 10^14
        SC: O(1)
    */
    std::uint64_t countCarsRepaired(const std::vector<int>& ranks, std::uint64_t time) {
        std::uint64_t cars_repaired = 0;
        for (const auto& rank : ranks)
            cars_repaired += static_cast<std::uint64_t>(std::sqrt(time / rank));
        return cars_repaired;
    }

    /*
        TC: O(N log M), where N == len(ranks), M == 10^14
        SC: O(1)
    */
    long long repairCars(std::vector<int>& ranks, int cars) {
        std::uint64_t left_time = 0;
        std::uint64_t right_time = static_cast<std::uint64_t>(std::pow(10, 14));

        while (right_time - left_time > 1) {
            std::uint64_t mid_time = left_time + (right_time - left_time) / 2;

            if (countCarsRepaired(ranks, mid_time) >= cars)
                right_time = mid_time;
            else
                left_time = mid_time;
        }
        return right_time;
    }
};
