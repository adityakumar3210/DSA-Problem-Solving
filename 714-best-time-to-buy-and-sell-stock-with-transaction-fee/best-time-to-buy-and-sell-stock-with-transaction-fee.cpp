class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();

        vector<vector<int> > t(n+1, vector<int> (2, 0));


        for(int i=n-1; i>=0; i--) {

            for(int buy=1; buy >= 0; buy--) {
  
                int result = 0;

                if(buy) {

                    int take = -prices[i] + t[i+1][0];
                    // solve(i+1, buy, k, prices);
                    int not_take = t[i+1][buy];

                    result = max({take, not_take, result});
                }
                else{
                    // solve(i+1, true, k-1, prices);
                    int sell = +prices[i] + t[i+1][1] - fee;

                    int not_sell = t[i+1][buy];

                    result = max({sell, not_sell, result});
                }

                t[i][buy] = result;

                    
                
            }
        }

        return t[0][1];
    }
};