
class Solution {
  public:

    bool isMaxHeap(int arr[], int n) {
        // Your code goes here
        int notleaf = n/2;
        for (int i = 0; i<=notleaf-1; i++)
        {
            int left = 2*i+1;
            int right = 2*i+2;
            int maxi = arr[i];
            if (left<=n-1 && right<=n-1)
            {
                maxi = max(arr[left],max(arr[right],arr[i]));
            }
            else if (left<=n-1)
            {
                maxi = max(arr[left],arr[i]);
            }
            if (maxi!=arr[i])
            {
                return false;
            }
        }
        return true;
    }
};
