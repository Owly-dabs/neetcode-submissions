class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // get locations of treasure chest and add to q
        // while q not empty
        // add the 1 step up down left right if possible
        // label grid in place
        queue<int> qx;
        queue<int> qy;
        int m = grid.size();
        int n = grid[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 0) {
                    qx.push(i);
                    qy.push(j);
                }
            }
        }
        vector<vector<int>> dirs = {{1,0},
                                    {0,1},
                                    {-1,0},
                                    {0,-1}};
        while (!qx.empty()) {
            int x = qx.front();
            qx.pop();
            int y = qy.front();
            qy.pop();

            for (vector<int> d:dirs) {
                int nx = x + d[0];
                int ny = y + d[1];
                // limits requirement - Does nx,ny exist?
                // is it land?
                if (nx>=0 && nx<m && ny>=0 && ny<n) {
                    if (grid[nx][ny] == 2147483647) {
                        grid[nx][ny] = grid[x][y] + 1;
                        qx.push(nx);
                        qy.push(ny);
                    }
                }
            }
        }
    }
};
