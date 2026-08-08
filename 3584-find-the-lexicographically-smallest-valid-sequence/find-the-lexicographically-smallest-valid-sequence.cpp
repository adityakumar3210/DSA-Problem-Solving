class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        
        int n = word1.length(),
            m = word2.length();

        vector<int> surfix(n, 0);

        int i = n-1, j = m-1;

        while(i >= 0 && 0 <= j) {

            if(word1[i] == word2[j]) {
                surfix[i] = (i == n-1) ? 1 : surfix[i+1] + 1;
                i--, j--;
            }
            else{
                surfix[i] = (i == n-1) ? 0 : surfix[i+1];
                i--;
            }
        }

        i = n-1;

        while(i >= 0) {

            if(i+1 < n && surfix[i] == 0) 
                surfix[i] = surfix[i+1];
            i--;
        }


        vector<int> ans;

        i = 0, j = 0;
        bool flag = true;

        while(i < n && j < m) {

            if(word1[i] == word2[j]) {
                ans.push_back(i);
                i++, j++;
            }
            else{
                int len = m-(j+1);

                if(flag && (i+1 < n && surfix[i+1] >= len)) {
                    ans.push_back(i);
                    i++, j++;
                    flag = false;
                }
                else{
                    i++;
                }
            }
        }

        if(j == m) 
           return ans;

        return {};
    }
};