class Solution {
public:
    int n;
    int dp[1001][2][101];

    int solve(int i, bool buy, int k, vector<int>& prices) {

        if(i == n || k == 0) 
           return 0;

        if(dp[i][buy][k] != -1) 
           return dp[i][buy][k];

        int result = 0;

        
        if(buy) {

            int take = -prices[i] + solve(i+1, false, k, prices);

            int not_take = solve(i+1, buy, k, prices);

            result = max({take, not_take, result});
        }
        else{

            int sell = +prices[i] + solve(i+1, true, k-1, prices);

            int not_sell = solve(i+1, buy, k, prices);

            result = max({sell, not_sell, result});
        }

        return dp[i][buy][k] = result;
    }
    int maxProfit(int k, vector<int>& prices) {
        
        n = prices.size();

        memset(dp, -1, sizeof(dp));

        return solve(0, true, k, prices);
    }
};