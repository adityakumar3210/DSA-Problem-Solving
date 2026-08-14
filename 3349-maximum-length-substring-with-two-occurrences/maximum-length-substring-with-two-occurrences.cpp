class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int n    = s.length();
        int maxi =  0,
            j    =  0;

        vector<int> freq(26, 0);

        for(int i=0; i<n; i++) {
            
            int idx = s[i] - 'a';
            freq[idx]++;

            while(freq[idx] > 2) {
                
                freq[s[j] - 'a']--;
                j++;
            }

            maxi = max(maxi, i - j + 1);
        }

        return maxi;
    }
};