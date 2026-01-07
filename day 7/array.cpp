class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int totalSum = 0;

        for (int num : nums) {
            int temp = num;
            int maxDigit = 0;
            int length = 0;

            // Find maximum digit and count digits
            while (temp > 0) {
                int digit = temp % 10;
                maxDigit = max(maxDigit, digit);
                length++;
                temp /= 10;
            }

            // Build encrypted number
            int encrypted = 0;
            for (int i = 0; i < length; i++) {
                encrypted = encrypted * 10 + maxDigit;
            }

            totalSum += encrypted;
        }

        return totalSum;
    }
};
