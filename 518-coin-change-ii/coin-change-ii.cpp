class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();

        vector<vector<int> > dp(n+1, vector<int> (amount+1, 0));

        for(int i=0; i<=n; i++)  dp[i][0] = 1;

        for(int i=1; i<=n; i++) {

            for(int j=1; j<=amount; j++) {

                if(coins[i-1] <= j) {

                    long long first  = dp[i][j - coins[i-1]];

                    long long second = dp[i-1][j];

                    long long currAns = first + second;

                    dp[i][j] = currAns > INT_MAX ? 0 : int(currAns);
                }
                else{

                    dp[i][j] = dp[i-1][j];
                }
            }

        }

        return dp[n][amount];


    }
};