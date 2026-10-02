class Solution {
public:

    void solve(string str, int open, int close, int size, vector<string>& result) {

        if(size*2 == str.length()) {
            result.push_back(str);
            return;
        }


        if(open < size)
            solve(str + "(", open+1, close, size, result);
        
        if(close < open)
           solve(str + ")", open, close+1, size, result);

    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;


        solve("", 0, 0, n, result);

        return result;
    }
};