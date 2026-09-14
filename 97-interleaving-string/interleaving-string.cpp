class Solution {
public:
    int n, m, len;
    int dp[101][101][201];

    bool solve(int i, int j, int k, string& s1, string& s2, string& s3) {

        if(k == len && (i < n || j < m))
            return false;

        if(k == len) 
            return true;

        if(s1[i] != s3[k] && s2[j] != s3[k]) 
           return false;

        if(dp[i][j][k] != -1) 
           return dp[i][j][k];

        if(s1[i] == s3[k] && s2[j] == s3[k]) {
            return dp[i][j][k] = solve(i+1, j, k+1, s1, s2, s3) || solve(i, j+1, k+1, s1, s2, s3);
        }
        else if(s1[i] == s3[k]) {
            return dp[i][j][k] = solve(i+1, j, k+1, s1, s2, s3);
        }
        else{
            return dp[i][j][k] = solve(i, j+1, k+1, s1, s2, s3);
        }


    }
    bool isInterleave(string s1, string s2, string s3) {
        
        n = s1.length();
        m = s2.length();
        len = s3.length();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0, s1, s2, s3);
    }
};