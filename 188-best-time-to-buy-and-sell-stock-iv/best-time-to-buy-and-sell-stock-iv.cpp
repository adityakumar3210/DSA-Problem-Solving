class Solution {
public:
    int n;
    int t[1001][101][2];

    int solve(int i, int k, bool purchase, vector<int>& prices) {

        if(i == n || k == 0) 
           return 0;

        if(t[i][k][purchase] != -1) 
           return t[i][k][purchase];
        
        int profit = 0;
        
        if(purchase) {

            int buy     = -prices[i] + solve(i+1, k, false, prices);

            int not_buy = solve(i+1, k, true, prices);

            profit = max({profit, buy, not_buy});
        }
        else{

            int sell     = prices[i] + solve(i+1, k-1, true, prices);

            int not_sell = solve(i+1, k, false, prices);

            profit = max({profit, sell, not_sell});
        }

        return  t[i][k][purchase] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        
        n = prices.size();

        memset(t, -1, sizeof(t));

        return solve(0, k, true, prices);
    }
};