//o(v+e), o(v+e)

// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,vector<pair<int,int>>> adjList;
        for (int i = 0; i<edges.size(); i++)
        {
            if (adjList.find(edges[i][0])==adjList.end())
            {
                adjList[edges[i][0]] = {};
            }
            adjList[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        queue<int> q;
        vector<int> topoSort;
        vector<int> indegree (V,0);
        for (int i = 0; i<V; i++)
        {
            for (pair<int,int> v: adjList[i])
            {
                indegree[v.first]++;
            }
        }
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topoSort.push_back(node);
            for (pair<int,int> v: adjList[node])
            {
                indegree[v.first]--;
                if(indegree[v.first]==0)
                {
                    q.push(v.first);
                }
            }
        }
        
        vector<int> ans(V,-1);
        ans[0]=0;
        
        for (int i: topoSort)
        {
            if (ans[i] == -1) continue;
            for (pair<int,int> p: adjList[i])
            {
                int v = p.first;
                int wt = p.second;
                if (ans[v] == -1 || ans[v] > ans[i] + wt)
                ans[v]=ans[i]+wt;
                
            }
        }
        return ans;
    }
};
