class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int l = 0; int r = arr.size()-1;
        int start = -1;
        int end = -1;
        while (l<=r)
        {
            int mid = l + (r-l)/2;
            if (arr[mid]>target)
            {
                r = mid-1;
            }
            else
            {
                if (arr[mid]==target) end = mid;
                l = mid+1;
            }
        }
        
        l = 0; r = arr.size()-1;
        
        while (l<=r)
        {
            int mid = l + (r-l)/2;
            if (arr[mid]<target)
            {
                l = mid+1;
            }
            else
            {
                if (arr[mid]==target) start = mid;
                r = mid-1;
            }
        
        }
        if (start==-1) return 0;
        
        return end-start+1;
    }
};
