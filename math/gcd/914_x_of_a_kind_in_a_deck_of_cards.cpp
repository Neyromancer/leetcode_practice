/*
class Solution {
public:
    // TC: O(N), where N == len(frequencies)
    bool areAllEqual(const std::vector<int>& frequencies) {
        return std::all_of(std::begin(frequencies), std::end(frequencies), 
        [validator = frequencies.front()](int val){
            return val == validator;
        });
    }

    // TC: O(N log N), where N == len(frequencies) (What is time complexity here?)
    // SC: O(N), where N == len(frequencies)
    int gcd(std::vector<int> frequencies) {
        int divisor = frequencies.front();
        for (auto it = std::begin(frequencies); it != std::end(frequencies); ++it) {
            if (*it % divisor)
                *it = *it % divisor;
        }

        std::sort(std::begin(frequencies), std::end(frequencies)); // O(N log N), where N == len(frequencies)
        int min_val = frequencies.front();
        for (auto& val : frequencies)
            if (val != min_val)
                val -= min_val;

        if (areAllEqual(frequencies)) // O(N), where N == len(frequencies)
            return frequencies.front();

        return gcd(frequencies);    
    }

    // TC: O(N log N), where N == len(frequencies)
    // SC: O(N), where N == len(frequencies)
    bool hasGroupsSizeX(vector<int>& deck) {
        std::unordered_map<int, int> cache;
        for (const auto& card : deck)
            cache[card]++; // O(1)
        
        std::vector<int> number_frequencies;
        for (const auto&[number, freq] : cache)
            number_frequencies.push_back(freq); // O(1)

        std::sort(std::begin(number_frequencies), std::end(number_frequencies)); // O(N log N), where N == len(frequencies)
        return gcd(number_frequencies) > 1;
    }
};
*/


