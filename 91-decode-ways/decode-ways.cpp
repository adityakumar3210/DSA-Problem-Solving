class Solution {
public:
    int n;
    int t[101];
    int solve(int i, string& s) {

        if(i == n) 
           return 1;

        if(s[i] == '0') 
           return 0;

        if(t[i] != -1) 
           return t[i];

        int count = 0;

        for(int j=i; j < min(i+2, n); j++) {

            if(i == j) {
                count += solve(j+1, s);
            }
            else{

                if(s[i] == '1' || s[i] == '2' && s[j] <= '6') {

                    count += solve(j+1, s);
                }
            }
        }

        return t[i] = count;
    }
    int numDecodings(string s) {
        
        n = s.length();

        memset(t, -1, sizeof(t));

        return solve(0, s);
    }
};