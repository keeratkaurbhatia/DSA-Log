//O(n), O(n)

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int rem = 0;  
        for (int i = 0; i < nums.size(); i++) {
            rem = (rem * 2 + nums[i]) % 5; 
            ans.push_back(rem == 0);
        }
        return ans;
    }
};
