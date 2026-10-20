class Solution {
public:
    int n;
    int maxProfit(vector<int>& prices) {
        
        n = prices.size();
        

        vector<vector<int> > dp(n+2, vector<int>(2, 0));

        for(int i=n-1; i>=0; i--) {

            for(int buy=1; buy>=0; buy--) {
                
                int result = 0;

                if(buy) {

                    int take = -prices[i] + dp[i+1][0];

                    int not_take = dp[i+1][buy];

                    result = max({take, not_take, result});
                }
                else{

                    int sell = +prices[i] + dp[i+2][1];

                    int not_sell = dp[i+1][buy];

                    result = max({sell, not_sell, result});
                }

                dp[i][buy] = result;

            }
        }

        return dp[0][1];
    }
};