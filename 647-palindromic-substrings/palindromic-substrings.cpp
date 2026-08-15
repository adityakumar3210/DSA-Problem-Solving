class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.length();
        int count = 0;
        vector<vector<int> > t(n, vector<int>(n));


        for(int L=1; L <= n; L++) {

            for(int i=0; i+L-1 < n; i++) {

                int j = i+L-1;

                // 1 length
                if(i == j) {
                    t[i][j] = true;
                }
                else if(i+1 == j) {
                    t[i][j] = (s[i] == s[j]) ? true : false;
                }
                else{
                    t[i][j] = ((s[i] == s[j]) && t[i+1][j-1] == true) ? true : false;
                }

                if(t[i][j]) 
                    count++;
            }
        }

        return count;
    }
};