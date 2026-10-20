class Solution {
public:
    int n;
    int t[5001][1001];

    int solve(int i, bool buy, vector<int>& prices) {
        
        if(i >= n) 
           return 0;

        if(t[i][buy] != -1) 
           return t[i][buy];

        int result = 0;

        if(buy) {

            int take = -prices[i] + solve(i+1, false, prices);

            int not_take = solve(i+1, buy, prices);

            result = max({take, not_take, result});
        }
        else{

            int sell = +prices[i] + solve(i+2, true, prices);

            int not_sell = solve(i+1, buy, prices);

            result = max({sell, not_sell, result});
        }

        return t[i][buy] = result;

    }
    int maxProfit(vector<int>& prices) {
        
        n = prices.size();
        
        memset(t, -1, sizeof(t));

        return solve(0, true, prices);
    }
};