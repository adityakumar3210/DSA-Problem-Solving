class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        int n = s.length();
        unordered_map<string, int> mp;

        vector<string> result;

        if(n <= 9) return result;


        int j=0;

        string str = "";

        for(j; j<10; j++) {

            str += s[j];
        }

        mp[str]++;

        for(j; j<n; j++) {

            str.erase(0, 1);

            str += s[j];

            mp[str]++;
        }


        for(auto it : mp) {

            if(it.second >= 2) {
                result.push_back(it.first);
            }
        }

        return result;


    }
};