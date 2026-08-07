class Solution {
public:
    string build_number(long long value, int slots) {
        string result = "";

        for (int digit = 9; digit >= 2; digit--) {
            while (value % digit == 0) {
                result.push_back(char('0' + digit));
                value /= digit;
            }
        }

        while ((int)result.size() < slots)
            result.push_back('1');

        reverse(result.begin(), result.end());
        return result;
    }

    string smallestNumber(string S, long long T) {
        
        int length = S.size();

        long long temp = T;

        for (int prime : {2, 3, 5, 7}) {
            while (temp % prime == 0)
                temp /= prime;
        }

        if (temp != 1)
            return "-1";

        vector<long long> need(length + 1, T);

        for (int idx = 0; idx < length; idx++) {
            int digit = S[idx] - '0';

            if (digit == 0)
                break;

            need[idx + 1] = need[idx] / gcd(need[idx], (long long)digit);
        }

        if (need[length] == 1)
            return S;

        int pos = S.find('0');

        if (pos == string::npos)
            pos = length - 1;

        for (int i = pos; i >= 0; i--) {

            long long current = need[i];
            int remaining = length - i - 1;

            int start = (S[i] - '0') + 1;

            for (int digit = start; digit <= 9; digit++) {

                long long left = current / gcd(current, (long long)digit);

                string suffix = build_number(left, remaining);

                if ((int)suffix.size() <= remaining) {
                    return S.substr(0, i) + char('0' + digit) + suffix;
                }
            }
        }

        return build_number(T, length + 1);

    }
};