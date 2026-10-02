class Solution {
public:
    bool checkVPS(string str) {

        int open = 0;

        for(int i=0; i<str.length(); i++) {

            if(str[i] == '(') {
                open++;
            }
            else{
                open--;
                if(open < 0)
                   return false;
            }
        }

        return open == 0;
    }
    void solve(string str, int& size, vector<string>& result) {

        if(size == str.length()) {
            if(checkVPS(str))
                result.push_back(str);
            return;
        }

        solve(str + "(", size, result);

        solve(str + ")", size, result);

    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;

        int size = n*2;

        solve("", size, result);

        return result;
    }
};