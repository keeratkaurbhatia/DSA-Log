//iterative- o(v+e), o(v)

class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> ans;
        stack<int> stk;
        vector<int> visited (adj.size(), 0);
        stk.push(0);
        while (!stk.empty())
        {
            int node = stk.top();
            stk.pop();
            if (visited[node]==0)
            {
                visited[node]=1;
                ans.push_back(node);
                for (int i = adj[node].size()-1; i>=0; i--)
                {
                    if(visited[adj[node][i]]==0) stk.push(adj[node][i]);
                }
            }
        }
        return ans;
    }
};

//recursive - o v+e, o v

class Solution {
  public:
    void dfsR(int k, vector<vector<int>>&adj, vector<int>&visited, vector<int>& ans)
    {
        visited[k] = 1;
        ans.push_back(k);
        for (int v: adj[k])
        {
            if(visited[v]==0)
            {
                dfsR(v,adj,visited,ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> ans;
        vector<int> visited (adj.size(), 0);
        dfsR(0,adj,visited,ans);
        return ans;
        
    }
};
