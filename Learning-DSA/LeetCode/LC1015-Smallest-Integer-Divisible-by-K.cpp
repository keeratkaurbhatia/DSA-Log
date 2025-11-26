//O(n), O(1)

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k==2 || k==5) return -1;
        int rem = 0;
        int len = 0;
        for (int i = 0; i<k; i++)
        {
            len++;
            rem = (rem*10+1)%k;
            if (rem==0) return len;
        }
        return -1;
    }
};
