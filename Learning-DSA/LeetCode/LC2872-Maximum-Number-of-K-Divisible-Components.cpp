//O(n),O(n)

class Solution {
    int ans = 0;
    long long dfsSum(int u, int parent,vector<int>& values,vector<vector<int>>& g, int k)
    {
        long long sum = values[u];
        for (int v:g[u])
        {
            if (v==parent) continue;
            sum+=dfsSum(v,u,values,g,k);
        }
        if (sum%k==0) ans++;
        return sum;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> g(n);
        for (auto e : edges) 
        {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
        }

        dfsSum(0, -1, values, g, k);
        return ans;


    }
};
