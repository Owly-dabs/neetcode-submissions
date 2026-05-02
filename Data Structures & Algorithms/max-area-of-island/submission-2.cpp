class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols,false));
        int max_area = 0;
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (grid[i][j]==1 && !visited[i][j]) {
                    int area = bfs(grid,i,j,visited);
                    max_area = (area>max_area) ? area : max_area;
                }
            }
        }
        return max_area;
    }
private: 
    int bfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = true;
        vector<vector<int>> dirs = {
            {1,0},
            {0,1},
            {-1,0},
            {0,-1}
            };
        int area = 1;
        while (!q.empty()){
            pair<int,int> coord = q.front();
            q.pop();
            for (vector<int> d:dirs) {
                int nr = coord.first + d[0];
                int nc = coord.second + d[1];
                if (0<=nr && nr<grid.size() &&
                 0<=nc && nc<grid[0].size() &&
                 grid[nr][nc] == 1 &&
                 !visited[nr][nc]){
                    q.push({nr,nc});
                    visited[nr][nc] = true;
                    area += 1;
                }
            }
        }
        return area;
    }
};
