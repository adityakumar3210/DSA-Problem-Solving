class Solution {
public:
    int t[501][501];
    int solve(int s, int e, int total, vector<int>& stoneValue) {

        if(s == e) 
            return 0;

        if(t[s][e] != -1) 
            return t[s][e];

        int result = INT_MIN;
        int score  = 0;
        int sum    = 0;

        for(int i=s; i<e; i++) {

            sum += stoneValue[i];
            int right = total - sum;

            if(right > sum) {
                
                score = sum + solve(s, i, sum, stoneValue);
                result = max(score, result);
                
            }
            else if(right < sum){
                score = right + solve(i+1, e, right, stoneValue);
                result = max(score, result);
                 
            }  
            else{  
            
                result = max(result, max(sum + solve(s, i, sum, stoneValue), right + solve(i+1, e, right, stoneValue)));

            }  

        }  

        return t[s][e] = result;

        
    }
    int stoneGameV(vector<int>& stoneValue) {
        
        int n = stoneValue.size();
        int total = accumulate(stoneValue.begin(), stoneValue.end(), 0);

        memset(t,-1, sizeof(t));

        return solve(0, n-1, total, stoneValue);
    }
};