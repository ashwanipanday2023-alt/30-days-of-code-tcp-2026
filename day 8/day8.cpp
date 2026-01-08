class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Put all numbers into an unordered_set for O(1) lookup
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int num : s) {
            // If num-1 is not in the set, then num is the start of a sequence
            if (!s.count(num - 1)) {
                int current = num;
                int streak = 1;

                // Count the length of the consecutive run
                while (s.count(current + 1)) {
                    current++;
                    streak++;
                }
                longest = max(longest, streak);
            }
        }
        return longest;
    }
};
