class Solution {
public:
    string solve(int n, string& s) {

        if(n == 0) 
           return "";

        string ans = s + solve(n-1, s);

        return ans;
    }
    string decodeString(string s) {
        
        int n = s.length();

        stack<string> st;
        stack<int>    num;

        for(int i=0; i<n; i++) {

            
            if(s[i] >= '0' && s[i] <= '9') {

                if(i+2 < n && (s[i+1] >= '0' && s[i+1] <= '9' && s[i+2] >= '0' && s[i+2] <= '9')) {

                    num.push(stoi(s.substr(i, 3)));
                    i = i+2;
                }
                else if(i+1 < n &&  s[i+1] >= '0' && s[i+1] <= '9') {
                    num.push(stoi(s.substr(i, 2)));
                    i = i+1;
                }
                else{
                    num.push(s[i] - '0');
                }
            }
            else if(s[i] == '[' || s[i] >= 'a' && s[i] <= 'z') {
                st.push(string(1, s[i]));

            }
            else{

                string temp = "";

                while(st.top() != "[") {

                    temp = st.top() + temp;
                    st.pop();

                }
                st.pop();
                int k = num.top(); num.pop();

                string ans = "";

                ans = solve(k, temp);

                st.push(ans);
            }
        }

        string result = "";

        while(!st.empty()) {

            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};