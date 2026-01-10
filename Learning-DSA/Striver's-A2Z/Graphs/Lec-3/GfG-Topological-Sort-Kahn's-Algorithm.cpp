//o(v+e), o(v+e)

class Solution {
  public:
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
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
        
        vector<int> indegree(V,0);
        for (int i = 0; i<V; i++)
        {
            for (int v : adjList[i])
            {
                indegree[v]++;
            }
        }
        queue<int> q;
        for(int i = 0; i<V; i++)
        {
            if (indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int> ans = {};
        
        while (!q.empty())
        {
            int node = q.front();
            
            q.pop();
            ans.push_back(node);
            for (int i: adjList[node])
            {
        
                    indegree[i]--;
                    if(indegree[i]==0)
                    {
                        q.push(i);
                    }
 
            }
        }
        return ans;
    }
};
