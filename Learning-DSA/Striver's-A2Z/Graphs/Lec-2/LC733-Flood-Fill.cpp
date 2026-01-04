class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
   
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int before = image[sr][sc];
        vector<vector<int>> visited (image.size(), vector<int>(image[0].size(),0));

        while (!q.empty())
        {
            pair<int,int> node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            image[x][y]=color;
            
            vector<pair<int,int>> dir = 
            {
                {-1,0},{1,0},{0,-1},{0,1}
            };
            for (pair<int,int> p:dir)
            {
                int nx = x+p.first;
                int ny = y+p.second;
                if (nx>=0 && nx<image.size() && ny>=0 && ny<image[0].size())
                {
                    if (image[nx][ny]==before && visited[nx][ny]==0)
                    {
                        q.push({nx,ny});
                    }
                }
            }
            visited[x][y]=1;
        }
        return image;
    }
};
