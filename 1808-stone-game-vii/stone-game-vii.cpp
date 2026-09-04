class Solution {
public:
    int t[1001][1001];

    int solve(int i, int j, int total, vector<int>& stones) {

        if(i > j) 
            return 0;

        if(t[i][j] != -1) 
            return t[i][j];

        int result = 0;

        int take_s = total - stones[i] - solve(i+1, j, total - stones[i], stones);

        int take_e = total - stones[j] - solve(i, j-1, total - stones[j], stones);

        return t[i][j] = max({result, take_s, take_e});

    }
    int stoneGameVII(vector<int>& stones) {
        
        int n     = stones.size();
        int total = accumulate(stones.begin(), stones.end(), 0);
        
        memset(t, -1, sizeof(t));

        return solve(0, n-1, total, stones);

    }
};