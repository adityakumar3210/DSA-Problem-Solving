class Solution {
public:
    const int INF = 1e9;
    int n;
    int dp[13][10001];

    int solve(int i, int amount, vector<int>& coins) {
        
        // possible path
        if(amount == 0)
           return 0;

        if(i == n)
           return INF;

        if(dp[i][amount] != -1) 
           return dp[i][amount];

        
        if(coins[i] <= amount) {
            // 2 options : use karo ya nhi karo
            return dp[i][amount] = min(1+solve(i, amount - coins[i], coins), solve(i+1, amount, coins));
        }
        else{
            return dp[i][amount] = solve(i+1, amount, coins);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        
        n = coins.size();

        memset(dp, -1, sizeof(dp));

        int ans = solve(0, amount, coins);

        return ans >= INF ? -1 : ans;
    }
};