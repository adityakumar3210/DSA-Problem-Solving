class Solution {
public:
    int n;
    int t[1001];
    int solve(int i, vector<int>& cost) {

        if(i >= n) 
            return 0;
        
        if(t[i] != -1) 
            return t[i];
        
        int step_1 = cost[i] + solve(i+1, cost);
        int step_2 = cost[i] + solve(i+2, cost);

        return t[i] = min(step_1, step_2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        n = cost.size();

        memset(t, -1, sizeof(t));

        return min(solve(0, cost), solve(1, cost));
    }
};