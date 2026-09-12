class Solution {
public:
    int n, m;
    int t[201][201];
    int solve(int r, int c, vector<vector<int>>& triangle) {

        if(r == n || c == m) 
            return 0;

        if(t[r][c] != INT_MAX) 
            return t[r][c];

        return t[r][c] = triangle[r][c] + min(solve(r+1, c, triangle), solve(r+1, c+1, triangle));

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        n = triangle.size();
        m = triangle[n-1].size();

        memset(t, -1, sizeof(t));

        for(int i=0; i<201; i++) 
           for(int j=0; j<201; j++) 
              t[i][j] = INT_MAX;


        return solve(0, 0, triangle);
    }
};