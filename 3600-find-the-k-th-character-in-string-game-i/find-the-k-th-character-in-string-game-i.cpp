class Solution {
public:
    char kthCharacter(int k) {
        
        string s = "a";

        while(s.length() < k) {

            string str = "";

            for(int i=0; i<s.length(); i++) {

                int idx = s[i] - 'a';
                if(idx  < 25) {
                    str += idx+1 + 'a';
                }
                else{
                    str += 'a';
                }
            }

            s += str;

        }

        return s[k-1];
    }
};