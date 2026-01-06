class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;        // just add 1 and return
                return digits;
            }
            digits[i] = 0;          // make it 0 if it was 9
        }
        
        // If all digits were 9 → we need an extra digit
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
