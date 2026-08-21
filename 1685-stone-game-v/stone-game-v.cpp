class Solution {
public:
    int t[501][501];
    int solve(int s, int e, int total, vector<int>& stoneValue) {

        if(s > e) 
           return 0;

        if(t[s][e] != -1) 
           return t[s][e];

        int result = 0,
            sum    = 0;

        for(int X=1; X <= e-s+1; X++) {
            int i = X+s-1;
            sum +=  stoneValue[i];

            int reamaing = total - sum;

            if(reamaing > sum) {
                // left part
                result = max(result, sum + solve(s, i, sum,  stoneValue));
            }
            else if(sum > reamaing) {
                // right part
                result = max(result , reamaing + solve(i+1, e, reamaing,  stoneValue));
            }
            else{
                // Equal 
                result = max(result , sum + max(solve(s, i, sum,  stoneValue), solve(i+1, e, reamaing,  stoneValue)));
            }
        }

        return t[s][e] = result;
    }
    int stoneGameV(vector<int>& stoneValue) {
        
        int n = stoneValue.size();
        int total = accumulate(stoneValue.begin(), stoneValue.end(), 0);

        memset(t, -1, sizeof(t));

        return solve(0, n-1, total, stoneValue);
    }
};