//o(v+e), o(v+e)

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        //level order with bfs
        unordered_map<int,vector<int>> adjList;
        
        for (int i = 0; i<edges.size(); i++)
        {
            if (adjList.find(edges[i][0])==adjList.end())
            {
                adjList[edges[i][0]] = {};
            }
            if (adjList.find(edges[i][1])==adjList.end())
            {
                adjList[edges[i][1]] = {};
            }
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        int level = 0;
        vector<int> ans (V,-1);
        vector<int> visited (V,0);
        q.push(src);
        visited[src]=1;
        
        while(!q.empty())
        {
            int size = q.size();
            for (int i = 0; i<size; i++)
            {
                int node = q.front();
                q.pop();
                
                ans[node]=level;
                for (int v: adjList[node])
                {
                    if(!visited[v])
                    {
                        visited[v]=1;
                        q.push(v);
                    }
                }
            }
            level++;
        }
        return ans;
    }
};
