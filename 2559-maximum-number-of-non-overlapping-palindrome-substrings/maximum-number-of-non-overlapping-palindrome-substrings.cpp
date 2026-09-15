class Solution {
public:
    int n;
    int t[2001][2001];
    int dp[2001];

    bool isPalindrome(int i, int j, string& s) {

        if(i > j) 
            return true;

        if(s[i] != s[j]) 
            return false;

        if(t[i][j] != -1) 
            return t[i][j];

        return t[i][j] = isPalindrome(i+1, j-1, s);
    } 
    int solve(int idx, int k, string& s) {

        if(idx == n) 
           return 0;

        if(dp[idx] != -1) 
           return dp[idx];

        int result  = solve(idx+1, k, s);

        for(int j=idx; j<n; j++) {

            if((j-idx+1 >= k) && isPalindrome(idx, j, s)) {

                result = max(result, 1 + solve(j+1, k, s));

            }
        }
    
        return dp[idx] = result;
    }
    int maxPalindromes(string s, int k) {
        
        n = s.length();

        memset(t, -1, sizeof(t));
        memset(dp, -1, sizeof(dp));

        return solve(0, k, s);
    }
};