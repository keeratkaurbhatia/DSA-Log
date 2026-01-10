//o(v+e),o(v+e)

class Solution {
public:
    bool dfs(int node, vector<int>& visited, unordered_map<int,vector<int>>& adjList, stack<int>& stk)
    {
        visited[node]=1;
        
        for (int i: adjList[node])
        {
            if (!visited[i])
            {
                visited[i]=1;
                if (dfs(i,visited,adjList,stk))
                    return true;
            }
            else if (visited[i]==1)
                return true;
        }
        visited[node]=2;
        stk.push(node);
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adjList;
        vector<int> visited (numCourses, 0);
        stack<int> stk;

        for (int i = 0; i<prerequisites.size();i++)
        {
            if (adjList.find(prerequisites[i][1])==adjList.end())
            {
                adjList[prerequisites[i][1]]={};
            }
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for (int i = 0; i<numCourses; i++)
        {
            if(!visited[i])
            {
                if(dfs(i,visited,adjList,stk))
                    return false;
            }
        }
        return true;
    }
};
