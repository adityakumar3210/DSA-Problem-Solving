class Solution {
public:
    int dp[1001][1001];

    int solve(int n, int m, string &text1, string &text2) {

        if(n == 0 || m == 0) 
            return 0;

        if(dp[n][m] != -1) 
            return dp[n][m];


        if(text1[n-1] == text2[m-1]) {

            return dp[n][m] = 1 + solve(n-1, m-1, text1, text2);
        }
        else{

            return dp[n][m] = max(solve(n-1, m, text1, text2), solve(n, m-1, text1, text2));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.length(),
            m = text2.length();

        memset(dp, -1, sizeof(dp));


        return solve(n, m, text1, text2);
    }
};