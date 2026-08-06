class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        // effort[i][j] = minimum effort required to reach cell (i,j)
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        // {effort, {row, col}}
        priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>> > pq;

        effort[0][0] = 0;
        pq.push({0, {0,0}});

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int currEffort = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;

            // Ignore outdated entries
            if (currEffort > effort[r][c])
                continue;

            // Destination reached
            if (r == m - 1 && c == n - 1)
                return currEffort;

            // Visit all 4 neighbours
            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                // Boundary check
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                // Difference between current cell and neighbour
                int jump = abs(heights[r][c] - heights[nr][nc]);

                // Maximum effort encountered so far
                int newEffort = max(currEffort, jump);

                if (newEffort < effort[nr][nc]) {

                    effort[nr][nc] = newEffort;

                    pq.push({newEffort, {nr, nc}});
                }
            }
        }

        return 0;
    }
};
