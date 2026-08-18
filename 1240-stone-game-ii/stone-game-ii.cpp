class Solution {
public:
    int n,
        total;
    vector<int> prefix;

    int t[101][101];

    int solve(int idx, int M, vector<int>& piles) {

        if(idx == n) 
            return 0;

        if(t[idx][M] != -1) 
            return t[idx][M];

        int result = 0;
        int stones = 0;

        for(int X=1; X <= min(2*M, n-idx); X++) {
            
            int i = idx + X - 1;
            stones += piles[i];
            int remaining = total - prefix[i+1];

            int alice_take = stones + remaining -  solve(i+1, max(X, M), piles);

            result = max(alice_take, result);
        }

        return t[idx][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        
        n = piles.size();

        prefix.resize(n+1, 0);

        for(int i=1; i<=n; i++) 
           prefix[i] = piles[i-1] + prefix[i-1];

        total = prefix[n];

        memset(t, -1, sizeof(t));

        return solve(0, 1, piles);
    }
};