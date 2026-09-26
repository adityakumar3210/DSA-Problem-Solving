class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        int n = s.length();
        string result = "";

        unordered_map<string, string> mp;

        for(auto pair : knowledge) {

            mp[pair[0]] = pair[1];
        }

        for(int i=0; i<n; i++) {

            if(s[i] == '(') {
                
                i++;
                string key = "";
                while(s[i] != ')') {
                    key += s[i++];
                }
                
                if(mp.find(key) != mp.end()) 
                    result += mp[key];
                else
                    result += '?';
            }
            else{

                if(s[i] != ')')
                    result += s[i];
            }

        }

        return result;


    }
};