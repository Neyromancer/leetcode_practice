#include <vector>
#include <queue>
#include <utility>

class Solution {
    // TC: O(log N), where N == len(troop)
    // SC: O(1)
    int countNumberOfSoldiers(const std::vector<int> &troop) {
        int l = 0;
        int r = troop.size();
        while( r - l > 1) {
            int m = l + (r - l) / 2;

            if (troop[m] < 1)
                r = m;
            else
                l = m;
        }

        if (troop[l] == 1)
            return l;
        return -1;
    }
public:

    /*
        TC: O(log M * log N), where M == len(mat[)) and N == len(mat0])
        SC: O(M), where M == len(mat)
    */
    std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {
        using row_weakness_t = std::pair<int, int>;
        auto cmp = [](const row_weakness_t &v1, const row_weakness_t &v2 ) {
            return std::get<0>(v1) < std::get<0>(v2) || 
            (std::get<0>(v1) == std::get<0>(v2) && std::get<1>(v1) < std::get<1>(v2));
        };
        std::priority_queue<row_weakness_t, std::vector<row_weakness_t>, decltype(cmp)> pq{cmp};
        for (std::size_t i = 0; i < mat.size(); ++i) {
            pq.push(std::make_pair(countNumberOfSoldiers(mat[i]), i)); // O(log M * log N), where M == len(mat[)) and N == len(mat0])

            if (pq.size() > k)
                pq.pop(); // O(log M), where M == len(mat[))
        }

        std::vector<int> res(pq.size()); // O(N), where N == len(pq)
        int cnt = pq.size() - 1;
        while(!pq.empty()) { // O(1)
            res[cnt--] = std::get<1>(pq.top()); // O(1)
            pq.pop();  // O(log M), where M == len(mat[))
        }
        return res;
    }
};
