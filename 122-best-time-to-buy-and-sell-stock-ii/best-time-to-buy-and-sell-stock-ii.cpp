class Solution {
public:
    int n;
    // int dp[30001][2];

    // int solve(int i, bool buy, vector<int>& prices) {

    //     if(i == n) 
    //        return 0;

    //     if(dp[i][buy] != -1) 
    //        return dp[i][buy];

    //     int result = 0;
        
    //     if(buy) {

    //         int take = -prices[i] + solve(i+1, false, prices);

    //         int not_take = solve(i+1, buy, prices);

    //         result = max({take, not_take, result});
    //     }
    //     else{

    //         int sell = prices[i] + solve(i+1, true, prices);

    //         int not_sell = solve(i+1, buy, prices);

    //         result = max({sell, not_sell, result});
    //     }

    //     return dp[i][buy] = result;

    // }
    int maxProfit(vector<int>& prices) {
        
        n = prices.size();

        // memset(dp, -1, sizeof(dp));

        // return solve(0, true, prices);

        vector<vector<int> > dp(n+1, vector<int> (2, 0));

        for(int i=n-1; i>=0; i--) {

            for(int buy=1; buy>=0; buy--) {

                int result = 0;

                if(buy) {

                    int take = -prices[i] + dp[i+1][0];
                    
                    int not_take =  dp[i+1][buy];

                    result = max({take, not_take, result});
                   
                }
                else{

                    int sell = prices[i] + dp[i+1][1];
                    
                    int not_sell = dp[i+1][buy];

                    result = max({sell, not_sell, result});
                     
                }

                dp[i][buy] = result;
            }
        }

        return dp[0][1];
    }
};