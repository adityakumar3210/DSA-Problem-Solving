class Solution {
public:
    char solve(string s, int k) {

        if(s.length() >= k) 
            return s[k-1];

        
        string str = "";

        for(int i=0; i<s.length(); i++) {

            int idx = s[i] - 'a';
            if(idx < 25) {
                str += idx + 1 + 'a';
            }
            else{
                str += 'a';
            }
        }

        return solve(s+str, k);
    }
    char kthCharacter(int k) {
        

        return solve("a", k);
    }
};