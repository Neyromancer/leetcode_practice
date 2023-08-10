class Solution {
public:
    /*
        TC: O(log N), where N == m
        SC: O(1)
    */
    std::uint64_t countCoins(std::uint64_t m) {
        return m * (m + 1) / 2;
    }

    int arrangeCoins(int n) {
        int l = 1;
        int r = n;

        while (r - l > 1) {
            int m = l + (r - l) / 2;

            if (countCoins(m) > static_cast<std::uint64_t>(n))
                r = m;
            else
                l = m;
        }
        return l;
    }
};
