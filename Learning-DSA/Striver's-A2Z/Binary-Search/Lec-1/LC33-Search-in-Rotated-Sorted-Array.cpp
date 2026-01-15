class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        

        
        while (l < r) 
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) 
            {
                l = mid + 1;
            } 
            else 
            {
                
                r = mid;
            }
        }
        int k = l;

        
        l = 0; r = n - 1;
        if (target >= nums[k] && target <= nums[r]) 
        {
            l = k;
        } 
        else 
        {
            r = k - 1;
        }

        
        while (l <= r) 
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }

        return -1;
    }
};
