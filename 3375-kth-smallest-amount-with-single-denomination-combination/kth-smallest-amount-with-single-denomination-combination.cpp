#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, vector<long long>> subsetLcmBySize;

    long long gcd(long long a, long long b) {
        return std::gcd(a, b);
    }

    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }

    vector<int> filterRedundantCoins(vector<int>& coins) {
        int n = coins.size();
        vector<bool> keep(n, true);

        for (int i = 0; i < n; i++) {
            if (!keep[i]) continue;
            for (int j = i + 1; j < n; j++) {
                if (coins[j] % coins[i] == 0) {
                    keep[j] = false;
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (keep[i]) result.push_back(coins[i]);
        }
        return result;
    }

    void precomputeSubsetLcms(const vector<int>& nums, int n) {
        subsetLcmBySize.clear();
        for (int i = 1; i <= n; i++) {
            subsetLcmBySize[i] = vector<long long>();
        }

        for (int mask = 1; mask < (1 << n); mask++) {
            int subsetSize = 0;
            long long currentLcm = 1;

            for (int bit = 0; bit < n; bit++) {
                if ((mask >> bit) & 1) {
                    subsetSize++;
                    currentLcm = lcm(currentLcm, nums[bit]);
                }
            }
            subsetLcmBySize[subsetSize].push_back(currentLcm);
        }
    }

    long long countMultiples(long long target, int n) {
        long long totalCount = 0;
        int sign = 1;

        for (int size = 1; size <= n; size++) {
            if (subsetLcmBySize.find(size) == subsetLcmBySize.end()) continue;
            for (long long lcmVal : subsetLcmBySize[size]) {
                totalCount += sign * (target / lcmVal);
            }
            sign = -sign;
        }

        return totalCount;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());

        vector<int> uniqueCoins = filterRedundantCoins(coins);
        int n = uniqueCoins.size();

        precomputeSubsetLcms(uniqueCoins, n);

        long long low = uniqueCoins[0];
        long long high = 1LL * uniqueCoins[0] * k;
        long long answer = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = countMultiples(mid, n);

            if (count >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return answer;
    }
};