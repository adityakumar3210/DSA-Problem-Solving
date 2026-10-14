class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        int K = k;


        vector<vector<vector<int> > > dp(n+1, vector<vector<int> > (K+1, vector<int> (2, 0)));

        for(int i=n-1; i>=0; i--) {

            for(int k=1; k<=K; k++) {


                for(int buy=1; buy>=0; buy--) {

                    int profit = 0;

                    if(buy == 1) {
                         
                        int take     = -prices[i] + dp[i+1][k][0];
                
                        int not_take =  dp[i+1][k][1];
                        

                        profit = max({profit, take, not_take});

                    }
                    else{
                        
                        int sell     = prices[i] +  dp[i+1][k-1][1];

                        int not_sell =  dp[i+1][k][0];
                       

                        profit = max({profit, sell, not_sell});

                    }

                    dp[i][k][buy] = profit;
                }

               
            }
        }

        return dp[0][K][1];
    }
};