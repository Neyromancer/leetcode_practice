class Solution {
public:
    /*
      TC: O(N log N), where N == len(ages)
      SC: O(N), where N == len(ages)
    */
    int numFriendRequests(vector<int>& ages) {
        std::sort(std::begin(ages), std::end(ages)); // TC: O(N log N), where N == len(ages), SC: O(log N)
        std::vector<std::vector<int>> cache; 
        cache.reserve(ages.size());
        int i = 0;
        // TC: O(N), where N == len(ages)
        // SC: O(N), where N == len(ages)
        while (i < ages.size()) {
            int cnt = 0;
            int current_age = ages[i];
            while (i < ages.size() && current_age == ages[i]) {
                ++cnt;
                ++i;
            }
            
            cache.push_back({current_age, cnt});
        }

        auto doNotMakeRequest = [](int left_age_limit, int right_age_limit){
            return (left_age_limit <= 0.5 * right_age_limit + 7) || (left_age_limit > right_age_limit);
        };

        int l = 0;
        // TC: O(N), where N == len(ages)
        // SC: O(1)
        while (l < cache.size() && doNotMakeRequest(cache[l][0], cache[l][0]))
            ++l;

        int result = 0;
        int recipients = 0;
        // TC: O(N), where N == len(ages)
        // SC: O(1)
        for (int r = l; r < cache.size(); ++r) {
            while (l < r && doNotMakeRequest(cache[l][0], cache[r][0])) {
                recipients -= cache[l][1];
                ++l;
            }

            result += cache[r][1] * recipients;
            result += cache[r][1] * (cache[r][1] - 1);
            recipients += cache[r][1];
        }
        return result;
    }
};
