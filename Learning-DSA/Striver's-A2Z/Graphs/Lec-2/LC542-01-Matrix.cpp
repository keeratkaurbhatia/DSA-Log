//o(mn), o(mn)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        vector<vector<int>> visited (mat.size(), vector<int>(mat[0].size(),0));
        for(int i = 0; i<mat.size(); i++)
        {
            for (int j = 0; j<mat[0].size(); j++)
            {
                if (mat[i][j]==0)
                {
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        
        int level = 0;
        while (!q.empty())
        {
            
            vector<pair<int,int>> dir = 
            {{-1,0},{1,0},{0,-1},{0,1}};

            int size = q.size();

            for (int i = 0; i<size; i++)
            {
                pair<int,int> node = q.front();
                
                q.pop();

                int x = node.first;
                int y = node.second;

                visited[x][y]=1;
                mat[x][y]=level;
                
                for (pair<int,int> p:dir)
                {
                    int nx = x + p.first;
                    int ny = y + p.second;
                    if (nx>=0 && nx<mat.size() && ny>=0 && ny<mat[0].size())
                    {
                        if (!visited[nx][ny])
                        {
                            q.push({nx,ny});
                            visited[nx][ny]=1;
                        }
                    }
                }
            }
            level++;
        }
        return mat;
    }
};
