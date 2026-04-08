class Solution {
  public:
    
    void heapify (int idx, vector<int> &arr)
    {
        int li = 2*idx + 1;
        int ri = 2*idx + 2;
        int smol = idx;
        if (li<arr.size() && arr[li]<arr[smol])
        {
            smol = li;
        }
        if (ri<arr.size() && arr[ri]<arr[smol])
        {
            smol = ri;
        }
        if(smol!=idx)
        {
            swap(arr[idx],arr[smol]);
            heapify(smol,arr);
        }
    }

    int extractMax (vector<int> &arr)
    {
        int mini = arr[0];
        arr[0] = arr[arr.size()-1];
        arr.pop_back();
        heapify(0, arr);

        return mini;
    }
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        for (int i = n/2-1; i>=0; i--)
        {
            heapify(i,arr);
        }

        int ans = INT_MAX;

        while (k!=0)
        {
            ans = extractMax(arr);
            k--;
        }
        
        return ans;
    }
};
