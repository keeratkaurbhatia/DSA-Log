// User function Template for C++

class Solution {
  public:
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        for (int i = arr.size()/2-1; i>=0; i--)
        {
            heapify(i, arr);
        }
    }
    void heapify(int idx, vector<int> &arr)
    {
        int ri = 2*idx+2;
        int li = 2*idx+1;
        int largest = idx;
        if (li<arr.size() && arr[li]>arr[largest])
        {
            largest = li;
        }
        if (ri<arr.size() && arr[ri]>arr[largest])
        {
            largest = ri;
        }
        if (largest!=idx)
        {
            swap(arr[idx],arr[largest]);
            heapify(largest, arr);
        }
    }
};
