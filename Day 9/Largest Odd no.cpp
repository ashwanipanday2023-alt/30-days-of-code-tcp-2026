class Solution {
public:
    string largestOddNumber(string num) {
        // Traverse from right to left
        for (int i = num.length() - 1; i >= 0; i--){
            // Check if digit is odd 
            if ((num[i] - '0') % 2 == 1) {
                //Return substring from start to this index
                return num.substr(0, i+1);
            }
        } 
        // No odd digit found
        return "";       
    }
};