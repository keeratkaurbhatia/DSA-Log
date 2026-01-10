//o(v+e), o(v+e)
class Solution {
  public:
    
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,vector<int>> adjList;
        for (int i = 0; i<edges.size(); i++)
        {
            if (adjList.find(edges[i][0])==adjList.end())
            {
                adjList[edges[i][0]]={};
            }
            adjList[edges[i][0]].push_back(edges[i][1]);
        }
        queue<int> q;
        vector<int> ans;
        vector<int> indegree (V,0);
        for (int i = 0; i<V; i++)
        {
            for (int v: adjList[i])
            {
                indegree[v]++;
            }
        }
        for (int i = 0; i<V; i++)
        {
            if (indegree[i]==0)
            {
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            count++;
            for (int v:adjList[node])
            {
                indegree[v]--;
                if (indegree[v]==0)
                {
                    q.push(v);
                }
            }
        }
        if (count<V)
        {
            return true;
        }
        return false;
        
    }
};
