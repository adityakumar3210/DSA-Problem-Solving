class Solution {
public:
    int n;
    unordered_map<int,int> mp;

    int t[2001][2001];

    bool solve(int i, int k, vector<int>& stones) {

        if(i == n-1)
            return true;

        if(t[i][k] != -1) 
            return t[i][k];

        for(int step=-1; step <= 1; step++) {

            int newStep = k + step;
            if(newStep > 0) {
                
                int nextJump = stones[i] + newStep;

                if(mp.count(nextJump)) {

                    if(solve(mp[nextJump], newStep, stones)) 
                        return t[i][k] = true;
                }
            }
           
        }

        return t[i][k] = false;
    }
    bool canCross(vector<int>& stones) {
        
        if(stones[1] != 1) return false;

        n = stones.size();

        for(int i=0; i<n; i++) 
           mp[stones[i]] = i;

        memset(t, -1, sizeof(t));

        return solve(1, 1, stones);
    }
};