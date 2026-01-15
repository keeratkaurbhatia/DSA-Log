class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //go to middle value
        //if adj equal, check the half with odd length
        //if no adj equal, that's the single element
        
        int l = 0;
        int r = nums.size()-1;
        while (l<r)
        {
            int mid = l + (r-l)/2;
            if (nums[mid-1]==nums[mid] && mid>l)
            {
                if ((mid-1-l)%2==1)
                {
                    r = mid - 2;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else if (nums[mid+1]==nums[mid] && mid<r)
            {
                if ((r-mid-1)%2==1)
                {
                    l = mid + 2;
                }
                else
                {
                    r = mid - 1;
                }
            }
            else return nums[mid];
        }
        return nums[l]; //l==r case
    }
};
