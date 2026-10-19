class Solution {
public:
   
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();

        vector<vector<vector<int> > > t(n+1, vector<vector<int> > (2, vector<int> (k+1, 0)));


        for(int i=n-1; i>=0; i--) {

            for(int buy=1; buy >= 0; buy--) {

                for(int j=1; j <= k; j++) {
                    
                    int result = 0;

                    if(buy) {

                        int take = -prices[i] + t[i+1][0][j];
                        // solve(i+1, buy, k, prices);
                        int not_take = t[i+1][buy][j];

                        result = max({take, not_take, result});
                    }
                    else{
                        // solve(i+1, true, k-1, prices);
                        int sell = +prices[i] + t[i+1][1][j-1];

                        int not_sell = t[i+1][buy][j];

                        result = max({sell, not_sell, result});
                    }

                    t[i][buy][j] = result;

                    
                }
            }
        }

        return t[0][1][k];
    }
};