class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        
        int n = digits.size();

        unordered_set<int> mp;

        for(int i=0; i<n; i++) {
            
            if(digits[i] == 0) continue;
            
            for(int j=0; j<n; j++) {

                if(j == i) continue;

                for(int k=0; k<n; k++) {
                      
                    if(k == i || k == j) continue;

                    if(digits[k] % 2 == 0) {

                       int num = digits[i];
                       num = num * 10 + digits[j];
                       num = num * 10 + digits[k];
                       mp.insert(num);
                    }
                       
                }
            }
        }

        return mp.size();
    }
};