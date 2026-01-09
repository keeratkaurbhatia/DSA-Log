//bfs
// o(v+e), o(v+e)
class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<int> visited (V,0);
        unordered_map<int,vector<int>> adjList;
    
        for (int i = 0; i<edges.size(); i++)
        {
            if (adjList.find(edges[i][0])==adjList.end())
            {
                adjList[edges[i][0]]={};
            
            }
            if (adjList.find(edges[i][1])==adjList.end())
            {
                adjList[edges[i][1]]={};
            }
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        for (int i = 0; i<V; i++)
        {
            if(!visited[i])
            {
                queue<pair<int,int>> q;
                q.push({i,-1});
                visited[i]=1;
                while(!q.empty())
                {
                    pair<int,int> node = q.front();
                    q.pop();
                    for (int nbr : adjList[node.first])
                    {
                        if (!visited[nbr])
                        {
                            visited[nbr]=1;
                            q.push({nbr,node.first});
                        }
                        else if (nbr != node.second)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};




















//dfs
// o(v+e), o(v+e)
class Solution {
  public:
    bool dfs(int node, int parent, vector<int>& visited, unordered_map<int,vector<int>>& adjList)
    {
        visited[node]=1;
        for (int nbr : adjList[node])
        {
            if(!visited[nbr])
            {
                if(dfs(nbr,node,visited, adjList))
                   return true; 
            }
            else if (nbr!=parent)
            {
                return true;
            }
        }
        return false;
    }
    
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<int> visited (V,0);
        unordered_map<int,vector<int>> adjList;
    
        for (int i = 0; i<edges.size(); i++)
        {
            if (adjList.find(edges[i][0])==adjList.end())
            {
                adjList[edges[i][0]]={};
            
            }
            if (adjList.find(edges[i][1])==adjList.end())
            {
                adjList[edges[i][1]]={};
            }
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        for (int i = 0; i<V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i,-1,visited, adjList))
                    return true;
            }
        }
        return false;
    }
};
