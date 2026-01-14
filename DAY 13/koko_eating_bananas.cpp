class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low) / 2;
            int hours = 0;

            for (int bananas : piles) {
                // ceil(bananas / mid)
                hours += (bananas + mid - 1) / mid;
            }

            if (hours <= h) {
                high = mid;        // mid speed works, try smaller
            } else {
                low = mid + 1;     // mid speed too slow
            }
        }

        return low;
    }
};
