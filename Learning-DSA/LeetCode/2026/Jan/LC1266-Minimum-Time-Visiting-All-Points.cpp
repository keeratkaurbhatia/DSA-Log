class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;

        for (int i = 1; i < points.size(); i++)
        {
            int x1 = points[i-1][0];
            int y1 = points[i-1][1];
            int x2 = points[i][0];
            int y2 = points[i][1];

            // same point
            if (x1 == x2 && y1 == y2)
            {
                continue;
            }

            // same row or same column (only straight moves)
            if (x1 == x2 || y1 == y2)
            {
                time += abs(x2 - x1) + abs(y2 - y1);
            }
            else
            {
                // diagonal moves first, then straight
                int dx = abs(x2 - x1);
                int dy = abs(y2 - y1);

                int diag = min(dx, dy); //diag is one horizontal+one vertical. min steps is min(dx,dy) to make such pairs
                int straight = max(dx, dy) - diag; //cant be paired is whatever the greater one is minus the pairs. as those got alloted to diag.

                time += diag + straight; 
            }
        }

        return time;
    }
};
