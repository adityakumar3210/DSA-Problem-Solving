class Solution {
public:
    int n, m;
    int t[501][501];

    int solve(int i, int j, string& word1, string& word2) {

        if(i == n || j == m) 
            return n + m - (i+j);

        if(t[i][j] != -1) 
            return t[i][j];

        if(word1[i] == word2[j]) {
            return t[i][j] = solve(i+1, j+1, word1, word2);
        }
        else{
            return t[i][j] = 1 + min({solve(i, j+1, word1, word2), solve(i+1, j, word1, word2), solve(i+1, j+1, word1, word2)});
        }
    }
    int minDistance(string word1, string word2) {
        
        n = word1.length(),
        m = word2.length();

        memset(t, -1, sizeof(t));

        return solve(0, 0, word1, word2);
    }
};