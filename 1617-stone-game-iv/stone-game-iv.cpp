class Solution {
public:
    int t[100001][2];
    bool solve(int n, int player) {

        if(n == 0) 
           return (player == 1) ? false : true;

        if(t[n][player] != -1) 
            return t[n][player];

        for(int i=1; i*i <= n; i++) {
            
            int sqr = i * i;

            if(player == 1) {

                if(solve(n-sqr, 0))
                    return t[n][player] = true;
            }
            else{

                if(!solve(n-sqr, 1)) 
                    return t[n][player] = false;
            }
        
        }

        return t[n][player] = (player == 1 ) ? false : true;
    }
    bool winnerSquareGame(int n) {
        
        memset(t, -1, sizeof(t));

        return solve(n, 1);
    }
};