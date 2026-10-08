class Solution {
public:
    string removeOuterParentheses(string s) {
        
        
        int count = 0;

        string result = "";
        string  ans   = "";

        
        for(char ch : s) {

            if(ch == '(') {
                count++;
                ans += ch;
            }
            else{
                count--;
                ans += ch;

                if(count == 0) {
                    ans.erase(0, 1);
                    ans.pop_back();
                    cout<< ans ;
                    result += ans;
                    ans = "";
                }
            }
        }

        return result;


    }
};