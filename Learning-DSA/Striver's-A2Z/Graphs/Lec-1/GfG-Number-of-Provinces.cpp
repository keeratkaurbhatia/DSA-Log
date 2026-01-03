// a mathematical approach, won't compile on platforms. 
// o(v3)= because of rank, o(v2)
#include <bits/stdc++.h>
#include <Eigen/Dense>
using namespace std;

class Solution {
public:
    int numProvinces(vector<vector<int>> adj, int V) {

        Eigen::MatrixXd L(V, V);
        L.setZero();

        // Build Laplacian L = D - A
        for (int i = 0; i < V; i++) {
            int degree = 0;
            for (int j = 0; j < V; j++) {
                if (i != j && adj[i][j] == 1) {
                    L(i, j) = -1;   // -A
                    degree++;
                }
            }
            L(i, i) = degree;       // D
        }

        // Number of connected components
        int components = V - L.rank();
        return components;
    }
};

//actual/required. 
//O(v2), o(v)
// User function Template for C++

class Solution {
  public:
    void dfs(int k, vector<vector<int>>& adj, vector<int>& visited)
    {
        visited[k]=1;
        for (int j = 0; j<adj.size(); j++)
        {
            if (adj[k][j]==1 && visited[j]==0)
            {
                dfs(j, adj, visited);
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> visited (V, 0);
        int count = 0;
        for (int i = 0; i<V; i++)
        {
            if (visited[i]==0)
            {
                dfs(i, adj, visited);
                count++;
            }
        }
        return count;
    }
};
