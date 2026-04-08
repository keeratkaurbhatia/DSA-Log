class Solution {
public:
    void heapify (int idx, vector<int> &arr)
    {
        int li = 2*idx + 1;
        int ri = 2*idx + 2;
        int largest = idx;
        if (li<arr.size() && arr[li]>arr[largest])
        {
            largest = li;
        }
        if (ri<arr.size() && arr[ri]>arr[largest])
        {
            largest = ri;
        }
        if(largest!=idx)
        {
            swap(arr[idx],arr[largest]);
            heapify(largest,arr);
        }
    }

    int extractMax (vector<int> &arr)
    {
        int maxi = arr[0];
        arr[0] = arr[arr.size()-1];
        arr.pop_back();
        heapify(0, arr);

        return maxi;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = n/2-1; i>=0; i--)
        {
            heapify(i,nums);
        }

        int ans = INT_MIN;

        while (k!=0)
        {
            ans = extractMax(nums);
            k--;
        }
        
        return ans;
    }
};
