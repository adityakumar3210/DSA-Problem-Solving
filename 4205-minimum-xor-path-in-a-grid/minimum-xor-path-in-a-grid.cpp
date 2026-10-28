
class Solution {
public:
    vector<vector<bitset<1024>>> dp;
    vector<vector<bool>> visited;

    bitset<1024> solve(int i, int j, vector<vector<int>>& grid) {

        if(i == 0 && j == 0) {
            bitset<1024> bs;
            bs[grid[i][j]] = 1;
            return bs;
        }

        if(visited[i][j])
            return dp[i][j];

        visited[i][j] = true;

        bitset<1024> up, left;

        if(i - 1 >= 0)
            up = solve(i - 1, j, grid);

        if(j - 1 >= 0)
            left = solve(i, j - 1, grid);

        bitset<1024> combined = up | left;
        bitset<1024> result;

        for(int k = 0; k < 1024; k++) {
            if(combined[k]) {
                result[k ^ grid[i][j]] = 1;
            }
        }

        return dp[i][j] = result;
    }

    int minCost(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        dp.resize(m, vector<bitset<1024>>(n));
        visited.resize(m, vector<bool>(n, false));

        bitset<1024> result = solve(m - 1, n - 1, grid);

        for(int i = 0; i < 1024; i++) {
            if(result[i])
                return i;
        }

        return 0;
    }
};
