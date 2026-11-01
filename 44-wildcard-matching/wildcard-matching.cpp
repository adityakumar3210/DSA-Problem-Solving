class Solution {
public:
    int n, m;
    int dp[2001][2001];

    bool check(string& p, int j) {

        bool flag = true;
        for(int k=j; k<m; k++) {
            if(p[k] != '*') {
                flag = false;
                break;
            }
        }

        return flag;
    }

    bool solve(int i, int j, string& s, string& p) {
        
        if(i == n && j == m) 
            return true;

        if(j == m) return false;

        if(i == n) 
            return check(p, j);
        
        
        if(dp[i][j] != -1)     
           return dp[i][j];

        if(p[j] == '*') { 
           
           return dp[i][j] = solve(i+1, j+1, s, p) || solve(i+1, j, s, p) || solve(i, j+1, s, p);
           
        }
        else if(p[j] == '?' || s[i] == p[j]) {

            return dp[i][j] = solve(i+1, j+1, s, p);
        }

        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        
        n = s.length(),
        m = p.length();
        


        memset(dp, -1, sizeof(dp));

        return solve(0, 0, s, p);
    }
};