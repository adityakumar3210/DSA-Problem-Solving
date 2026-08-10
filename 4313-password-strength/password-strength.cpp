class Solution {
public:
    int passwordStrength(string password) {
        
        int n = password.length();

        vector<int> lower(26, 0);
        vector<int> upper(26, 0);
        vector<int> digit(10, 0);
        vector<int> symbol(4, 0);

        for(int i=0; i<n; i++) {

            if(password[i] >= 'a' && password[i] <= 'z') {
                lower[password[i] - 'a'] = 1;
            }
            else if(password[i] >= 'A' && password[i] <= 'Z') {
                upper[password[i] - 'A'] = 1;
            }
            else if(password[i] >= '0' && password[i] <= '9'){
                digit[password[i] - '0'] = 1;
            }
            else if(password[i] == '!') {
                symbol[0] = 1;
            }
            else if(password[i] == '@') {
                symbol[1] = 1;
            }
            else if(password[i] == '#') {
                symbol[2] = 1;
            }
            else if(password[i] == '$') {
                symbol[3] = 1;
            }
        }

        int total = 0;

        for(int i=0; i<26; i++) {
            
            if(lower[i] == 1) {
                total  +=   1;
            }
            if(upper[i] == 1) {
                total += 2;
            }

            if(i < 10 && digit[i] == 1) {
                total += 3;
            }

            if(i < 4 && symbol[i] == 1) {
                total += 5;
            }
        }

        return total;
    }
};