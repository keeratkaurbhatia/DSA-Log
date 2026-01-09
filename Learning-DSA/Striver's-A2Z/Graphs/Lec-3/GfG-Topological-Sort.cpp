//o(v+e), o(v+e)

class Solution {
  public:
    void dfs (int node, unordered_map<int,vector<int>>& adjList, vector<int>& visited, stack<int>& stk)
    {
        visited[node]=1;
        for (int i : adjList[node])
        {
            if (!visited[i])
            {
                dfs(i,adjList,visited,stk);
            }
        }
        stk.push(node);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,vector<int>> adjList;
        vector<int> visited(V,0);
        for (int i = 0; i<edges.size(); i++)
        {
            if (adjList.find(edges[i][0])==adjList.end())
            {
                adjList[edges[i][0]]={};
            }
            adjList[edges[i][0]].push_back(edges[i][1]);
        }
        
        stack<int> stk;
        vector<int> ans = {};
        for (int i =0; i<V; i++)
        {
            if (!visited[i])
            {
                dfs(i,adjList,visited,stk);
            }
        }
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};
