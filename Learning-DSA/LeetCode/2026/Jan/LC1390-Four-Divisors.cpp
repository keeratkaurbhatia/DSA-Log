class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int i: nums)
        {
            int k = 2;
            int factors = 2;
            int factSum = 1+i;
            while (k <= sqrt(i))
            {
                if (i%k==0)
                {
                    if(factors>4) break;
                    
                    if(k==i/k)
                    {
                        factors += 1;
                        factSum += k;
                    }
                    else
                    {
                        factors += 2;
                        factSum += k + (i/k) ;
                    }
                }
                k++;
            }
            if (factors==4)
            {
                ans += factSum;
            }
        }
        return ans;
    }
};
