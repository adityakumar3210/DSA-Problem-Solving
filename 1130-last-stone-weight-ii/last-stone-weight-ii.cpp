class Solution {
public:

    int n;
    vector<vector<int> > dp;

    void isSubsetSum(vector<int>& arr, int sum) {
        
       
       for(int i=0; i<=n; i++) dp[i][0] = true;
       
       for(int i=1; i<=sum; i++) dp[0][i] = false;
       
       for(int i=1; i<=n; i++) {
           
           for(int j=1; j<=sum; j++) {
               
               if(arr[i-1] <= j) {
                   
                   dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
               }
               else{
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       
    }
    int lastStoneWeightII(vector<int>& stones) {
        
        n = stones.size();

        int total = accumulate(stones.begin(), stones.end(), 0);
        int sum = total / 2;

        dp.resize(n+1, vector<int> (sum+1));


        for(int i=0; i<=sum; i++) {

            isSubsetSum(stones, i);

        }

        int ans = INT_MAX;

        for(int i=0; i<=sum; i++) {

            if(dp[n][i] == true) {
                int s1 = i * 2;
                ans = min(ans, total - s1);
            }
        }

        return ans;



    }
};