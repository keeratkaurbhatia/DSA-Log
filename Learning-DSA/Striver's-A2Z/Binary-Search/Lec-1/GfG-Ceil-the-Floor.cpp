//o(n), o(1)

// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        vector<int> ans = {-1,-1};
        for (int i = 0 ; i<arr.size(); i++)
        {
            if (arr[i]>=x)
            {
                if (ans[1]==-1)
                {
                    ans[1]=arr[i];
                }
                else if (arr[i]<ans[1])
                {
                    ans[1]=arr[i];
                }
            }
            if (arr[i]<=x && arr[i]>ans[0])
            {
                ans[0]=arr[i];
            }
        }
        
        return ans;
    }
};
