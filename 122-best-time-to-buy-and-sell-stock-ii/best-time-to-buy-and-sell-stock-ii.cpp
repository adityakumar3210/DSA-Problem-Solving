class Solution {
public:
    int n;
    int dp[30001][2];

    int solve(int i, bool buy, vector<int>& prices) {

        if(i == n) 
           return 0;

        if(dp[i][buy] != -1) 
           return dp[i][buy];

        int result = 0;
        
        if(buy) {

            int take = -prices[i] + solve(i+1, false, prices);

            int not_take = solve(i+1, buy, prices);

            result = max({take, not_take, result});
        }
        else{

            int sell = prices[i] + solve(i+1, true, prices);

            int not_sell = solve(i+1, buy, prices);

            result = max({sell, not_sell, result});
        }

        return dp[i][buy] = result;

    }
    int maxProfit(vector<int>& prices) {
        
        n = prices.size();

        memset(dp, -1, sizeof(dp));

        return solve(0, true, prices);
    }
};