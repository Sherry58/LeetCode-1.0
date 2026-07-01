class Solution {
public:
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    int m,n;
    int result = 0;
    int nonObstacles = 0;
    void find(vector<vector<int>>& grid, int i, int j, int count){
        if(i<0 or j<0 or i>=m or j>=n or grid[i][j] == -1){
            return;
        }
        if(grid[i][j] == 2){
            if(count == nonObstacles){
                result++;
                return;
            }
        }

        int temp = grid[i][j];
        grid[i][j] = -1;

        for(auto &dir : directions){
            int new_i = i+dir[0];
            int new_j = j+dir[1];

            find(grid, new_i, new_j, count+1);
        }

        grid[i][j] = temp;
    }


    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int start_i = 0, start_j = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    nonObstacles++;
                }
                if(grid[i][j] == 1){
                    start_i = i;
                    start_j = j;
                }
            }

        }
        nonObstacles++;

        int count = 0;

        find(grid, start_i, start_j, count);

        return result;
    }
};