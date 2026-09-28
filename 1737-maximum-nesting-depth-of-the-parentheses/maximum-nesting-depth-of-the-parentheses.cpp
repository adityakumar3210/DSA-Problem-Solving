class Solution {
public:
    int maxDepth(string s) {
        
        int ans   = 0,
            count = 0;

        for(char ch : s) {

            if(ch == '(') {
                count++;
                ans = max(ans, count);
            }
            else if(ch == ')'){
                count--;
            }
            
        }

        return ans;


    }
};