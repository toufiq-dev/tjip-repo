int dx[] = {+0, +0, +1, -1};
int dy[] = {+1, -1, +0, +0};
class Solution {
public:
    void dfs(int ux, int uy, vector<vector<char>>& grid) {
        grid[ux][uy] = '0';
        for(int i = 0; i < 4; ++i) {
            int vx = ux + dx[i];
            int vy = uy + dy[i];

            if(vx < 0 || vy < 0 || vx >= grid.size() || vy >= grid[0].size() || grid[vx][vy] == '0')
                continue;
    
            dfs(vx, vy, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == '1') {
                    dfs(i, j, grid);
                    count++;
                }
            }
        }

        return count;
    }
};