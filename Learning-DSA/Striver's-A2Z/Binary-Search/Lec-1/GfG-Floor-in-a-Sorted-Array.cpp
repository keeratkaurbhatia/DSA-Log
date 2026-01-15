//o(n), o(1)

class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int index = -1;
        for (int i=0; i<arr.size(); i++)
        {
            if (arr[i]<=x)
            {
                index = i;
            }
            if (arr[i]>x)
            {
                break;
            }
        }
        return index;
    }
};
