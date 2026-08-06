class Solution {
public:
    vector<string> result;
    void solve(string s, int n) {

        if(s.length() == n) {
            result.push_back(s);
            return;
        }

        if(s.empty() || s[s.length()-1] == '1') {

            solve(s+"0", n);
            solve(s+"1", n);
        }
        else{
            solve(s+"1", n);
        } 
    }
    vector<string> validStrings(int n) {

        solve("", n);

        return result;
    }
};