//O(n),O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0] = 1; 
        int sum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (freq.find(sum - k) != freq.end()) {
                count += freq[sum - k]; 
            }
            freq[sum]++; 
        }

        return count;
    }
};
