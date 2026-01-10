class Solution {
public:
    
    //recursive=tle o(2^n), o(n)=recursion stack
    int ways(int n, int s)
    {
        if (s==n) return 1;
        if (s<n-1)
        {
            return ways(n,s+1)+ways(n,s+2);
        } 
        if (s==n-1)
        {
            return ways(n,s+1);
        }
        return 0;
    }
    
    int climbStairs(int n) {
        return ways(n,0);
    }






    //memoisation= accepted. o(n),o(n)
    vector<int> memo;

    int ways(int n, int s)
    {
        if (s==n) return 1;
        if (memo[s]!=-1) return memo[s];
        if (s<n-1)
        {
            return memo[s]=ways(n,s+1)+ways(n,s+2);
        } 
        if (s==n-1)
        {
            return memo[s]=ways(n,s+1);
        }
        return 0;
    }
    
    int climbStairs(int n) {
        memo.assign(n+1, -1);
        return ways(n,0);
    }




    //tabulation=accepted. o(n),o(n)
    
    vector<int> dp;

    int ways(int n, int s)
    {
        dp.assign(n+1,0);
        
        for(int i = n; i >= 0; i--){
        if (i==n) dp[i]=1;
        
        if (i<n-1)
        {
            dp[i]=dp[i+1]+dp[i+2];
        } 
        if (i==n-1)
        {
            dp[i]=dp[i+1];
        }
        }
        return dp[s];
    }
    
    int climbStairs(int n) {
        return ways(n,0);
    }


};
